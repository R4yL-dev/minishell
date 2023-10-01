# 1. Lexer

## 1.1. TDM

- [1. Lexer](#1-lexer)
	- [1.1. TDM](#11-tdm)
	- [1.2. Introduction](#12-introduction)
	- [1.3. Algorithme de déduction](#13-algorithme-de-déduction)
	- [1.4. Token](#14-token)
	- [1.5. Dyntklist](#15-dyntklist)
	- [1.6. Notes](#16-notes)


## 1.2. Introduction

Le but du `lexer` est de transformer l'input de l'utilisateur en une liste de `token`. Un `token` est l'unité fondamentale de la syntax de `minishell`, il se compose d'un `type` et d'une `value`. Le `lexer` est donc un algorithme qui se charge de déterminer le type de chaque élément de l'input de l'utilisateur. Afin d'organiser les `tokens`, ils peuvent être placé dans une `t_dyntklist`. Cette structure de donnée est en fait un container dynamique pour les `t_token`. Chaque fois qu'un élément est ajouté à la liste, la taille du tableau est augmentée automatiquement afin de pouvoir accueillir la nouvelle variable.

En résument, le `lexer`, reçoit un `char *` (l'input de l’utilisateur) et renvoie un `t_dyntklist *` (une liste de token, ordonné par ordre de découvert).

## 1.3. Algorithme de déduction

```text
Fonction lexer(str)
    Initialise tklist
    in_cmd = 0
    i = 0
    Tant que str[i] n'est pas '\0'
        Passer les espaces
        Si str[i] est '\0'
            Sortir de la boucle
        Si str[i] est un redirecteur
            Si str[i] est un pipe
                Ajouter un pipe
                in_cmd = 0
            Sinon
                Ajouter un redirecteur
                Passer les espaces
                Ajouter un file
        Sinon Si in_cmd est 0
            Ajouter commande
            in_cmd est 1
        Sinon
            Ajouter argument
        i++
    Retourne tklist
```

Afin de pouvoir tagué les tokens correctement, l'algorithme de déduction parcoure l'input de l'utilisateur caractère par caractère. Il passe tous les espaces afin de gérer les inputs ou l'utilisateur a multiplié les espace entre les tokens. En suite, il cherche à savoir si le caractère est une redirecteur (<, >, |). Si il est un redirecteur, il regarde si le caractère est un pipe.

Si le caractère est effectivement un pipe, un token de type pipe est ajouté à la tklist. La variable `in_cmd` est set à 0 afin de savoir que nous ne sommes plus entrain d'ajouter des élément à une commande.
Par contre, si le caractère est un autre redirecteur, le traitement est différent. Le redirecteur est ajouté à `tklist`, les espaces sont passé et le fils est ajouter directement à la liste. Cela vient du fait que plus tard, lorsque le programme voudra réorganiser la liste de tokens en un arbre syntaxique, chaque redirecteur aura forcement comme premier enfant un token de type file. Si un redirecteur n'a pas de file, cela est une `syntax error`.

Si le caractère n'est pas un redirecteur et que nous ne sommes pas dans une commande (`in_cmd = 0`), nous ajoutons la commande et nous passons `ìn_cmd` à 1 afin de signifier que nous avons ajouter une commande et que donc, les prochain élément que nous allons ajouter, si il n' est pas un redirecteur, sera un argument.

Sinon, nous ajoutons un argument.

Cette approche permet de prendre en compte les inputs avec ou sans espaces entre les éléments:

- `<in.txt grep foo` `< int.txt grep foo`
- `ls|wc` `ls | wc`
- `< <plein d'espace> int.txt <plein d'espace> grep <plein d'espace> foo|wc <plein d'espace> -l` `< int.txt grep foo|wc -l`

## 1.4. Token

Un token se compose d'un `type` et d'une `value` et est de type `t_token`.

```c
typedef struct s_token
{
    int     type;
    char    *value;
} t_token;
```

Le type du token est définit dans l'enumerateur `e_token_type` :

```c
enum e_token_type
{
    TK_COMMAND,     // == 0
    TK_ARGUMENT,    // == 1
    TK_FILE,        // == 2
    TK_REDIRECTION, // == 3
    TK_PIPE,        // == 4
};
```

Afin de pouvoir manipuler les tokens, `minishell` implémente deux fonctions :

- `t_token *token_new(int type, char *value)`, cette fonction prend en argument `type` et `value` et retourne un token initialisé en mémoire avec ces valeurs.
- `void token_free(t_token *token)`, cette fonction prend en argument l'adresse d'un token et libère proprement la mémoire qui lui est associé.

## 1.5. Dyntklist

Le type `t_dyntklist()` est une liste dynamique de `t_token`. Le but de ce type est de stocker un nombre indéfini de `t_token` dans une tableau de type `t_token **`. Ce tableau est redimensionné chaque fois qu'un élément est ajouter avec la fonction `dyntklist_add()`. Ce type comporte aussi un `size_t` `size` qui contient le nombre d'élément actuellement dans la liste.

```c
typedef struct s_dyntklist
{
    t_token **array;
    size_t  size;
}   t_dyntklist;
```

Voici les fonctions qui permette de manipuler un `t_dyntklist` :

- `t_dyntklist *dyntklist_init(t_dyntklist *tklist)`, cette fonction alloue la mémoire pour le tableau de `t_token`.
- `int dyntklist_add(t_dyntklist *tklist, int type, char *value)`, cette fonction prend en argument une `tklist`, un `type` ainsi qu'une `value` afin d'ajouter un nouveau token à la `tklist`.
- `void dyntklist_show(t_dyntklist *tklist)`, qui affiche le contenu de la `tklist` passée en argument.
- `int dyntklist_delone(t_dyntklist *tklist, int id)`, fonction qu prend en paramètre une `tklist` et un `id`. Elle supprime de la liste le bon élément et ré-index le tableau.
- `void dyntklist_free(t_dyntklist *tklist)`, libère proprement la mémoire utilisée par la `tklist` passée en argument.

## 1.6. Notes

- Il faudrait changer le fonctionnement de l'allocation mémoire de `t_dyntklist`. Pour le moment, chaque fois que nous ajoutons une élément à la liste, la fonction `dyntklist_add()` fait appel à la fonction `ft_realloc()`. Cette stratégie d'allocation est très coûteuse en ressource car la fonction `ft_realloc()` fait appel à `malloc()` et copie l'intégralité du contenu de l'ancienne plage mémoire vers la nouvelle.
Il faudrait utiliser la même stratégie que nous avons utiliser pour `t_dyntree`. C'est à dire, initialiser la liste avec une capacité de 2 élément et vérifier lors de l'ajout d'un nouvel élément que la liste a encore de la place. Si elle n'a plus de place elle double la taille de la liste.
- Pour le moment, l'algorithme de déduction des tokens cherche à passer les espaces, il faut sûrement aussi prendre en compte les tabulations.
- Cette version du lexer gère l'implémentation des variable. En effet, sa structure fait qu'il ne traite pas directement les variable. Il définit le token comme pour tous les autres et met dans ça `value`, le nom de la variable avec le `$`. La variable sera traité plus tard lors de l'`expand`.
- Le `lexer` n'est pas dans ça version définitive car il faudra encore ajouter des cas spécifiques, comme pour les quotes, que nous n'avons pas encore implémenté au moment ou je rédige ce document.
- Au moment de l'écriture de se document, le lexer ne passe pas la norme. Les fonctions sont beaucoup trop longue. Ce qui veut dire, que pour que le projet passe la norminette, nous devrons sûrement ré-organiser les fonctions en plusieurs sous fonctions et donc plusieurs fichier. La structure de lexer devrait donc changé avec le temps, mais la logique derrière l'algorithme de déduction ne devrait pas changer.
