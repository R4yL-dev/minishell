# Lexer

Le `lexer` est la première étape qui va être exécutée pour chaque input de l'utilisateur. Le but de cette fonction est de tranformer la chaine de caractère une une liste de `token`. Afin de pouvoir faire au mieux cette tâche, la fonction commence par nettoyer la frappe de l'utilisateur.

## Token

Un `token` reprèsente une mot. Il est le résultat du split de l'input de l'utilisateur sur le caractère espace.

En terme de structure, un `token` est de type `t_token` et comporte deux attribut :

- Le `type` sous forme d'`int`.
- La `value` sous forme de `char *`.

Afin de stocker les tokens dans un tableau dynamique, ils peuvent être ajouter à une liste de type `t_dyntklist`.

Le type `t_dyntklist` se compose de deux entrée :

- `array` qui est le tableau de `token` et qui est de type `t_token **`
- `size` qui est un `size_t` est qui correspond au nombre d'élements dans la liste

### Les types de tokens

Le but du lexer est de divisée la chaine de caractères entrée par l'utilisateur en token. Il doit aussi identifié à quoi correspond chaque token. C'est pourquoi un token est constituer d'un `type`.

Les types sont des entrée dans un `enum` qui se situe dans `token.h`. Les voici :

- `TK_COMMAND`
- `TK_ARGUMENT`
- `TK_FILE`
- `TK_REDIRECTION`
- `TK_PIPE`

Voici la listes des type de token présent au moment ou j'écris ces lignes. Durant le projet et selon nos besoin, nous allons surement rajouter des types de token.

### Logique d'atribution

Au moment ou j'écris ceci, nous avons un programe qui prend une commande est qui l'exécuter avec un nombre infie de d'argument.

Vu que les fonctionnalités ne sont pas très poussées, la logique d'atribution actuel du type de token est très simple :

```text
[PARCOURIR] le tableau spliter élément par élément
	[SI] l'élément est le premier du tableau splitter,
		[AJOUTER] un nouveau token de type TK_COMMAND
	[SINON]
		[AJOUTER] un nouveau token de type TK_ARGUMENT
```

Cette alghorytme est très simple et dévras évoler et se complexifier au fur et a mésure que nous étandons la capacité de notre programme pour détécter et traiter de nouveau type de token.

### Les fonctions sur les tokens

#### token_new()

```c
t_token *token_new(int type, char *value);
```

Le but de la fonction `token_new()` est de créer un nouveau token. Elle à pour but de résérver la mémoire pour pouvoir stocker le token et l'initialiser avec le `type` et la `value` passés en argument.

La fonction `token_new()` retourn :

- Un token (`t_token *`) em cas de succès.
- `NULL` en cas d'erreur.

```c
int	main(void)
{
	t_token	*token;

	token = NULL;
	token = token_new(TK_COMMAND, "ls");
	return (0);
}
```

#### token_free()

```c
void token_free(t_token *token);
```

Le but de la fonction `token_free()` et de nettoyer la mémoire allouée par `token_new()`. Afin de pouvoir passer dans tous les cas un token à la fonction `token_free()`, elle free que si le token est différent de `NULL`. Il faut donc absolument initialise chaque token générer manuellent à `NULL` afin d'éviter les problème de double free.


```c
int	main(void)
{
	t_token	*token;

	token = NULL;
	token = token_new(TK_COMMAND, "ls");
	token_free(token);
	return (0);
}
```

## Dyntklist

`t_dyntklist` est un type qui définit une structure. Cette structure est dynamique, c'est à dire que chaque fois que nous voulons ajouter un noueau token à la liste, elle sera automatiquement agrandie pour pouvoir reçevoir le nouvelle élément.

Une `t_dyntklist` continent deux éléments :

- `array`, qui est de type `t_token **`.
- `size`, qui est de type `size_t` et qui corréspond au nombre d'élément dans la liste.

### Les fonctions sur les dyntklist

Afin d'intéréagir avec un `t_dyntklist`, il existe pusieurs fonction. La première est `dyntklist_init()`, elle permet d'allouer l'espace en mémoire pour la liste, ainsi que pour le tableau de token. Une fois que la `t_dyntklist` est initialisée, nous pouvons ajouter de nouveau élément avec `dyntklist_add()`, l'afficher avec `dyntklist_show()` et libérer sa mémoire avec `dyntklist_free()`.

#### dyntklist_init()

```c
t_dyntklist	*dyntklist_init(t_dyntklist *tklist);
```

Il est important d'initialiser chaque list avec la fonction `dyntklist_init()`. Elle s'occupe de d'allouer la mémoire pour la liste en elle même ainsi que pour le tableau de tokens.

La fonction `dyntklist_init()` retourne :

- Une liste de token (`t_dyntklist *`) en cas de succès.
- `NULL` en cas d'échec.

```c
int	main(void)
{
	t_dyntklist	*tklist;

	tklist = NULL;
	tklist = dyntklist_init(tklist);
	return (0);
}
```


#### dyntklist_add()

```c
int	dyntklist_add(t_dyntklist *tklist, int type, char *value);
```

Une fois que la liste est initialisée, nous devons utiliser la fonction `dyntklist_add()` afin d'ajouter des éléments. Il faut impérativement passer par cette fonction car elle redimention automatiquement le tableau d'élément lors d'un nouvelle ajout.

La fonction `dyntklist_add()` retourne :

- `1` en cas de succès.
- `0` en cas d'erreur.

```c
int	main(void)
{
	t_dyntklist	*tklist;

	tklist = NULL;
	tklist = dyntklist_init(tklist);
	dyntklist_add(tklist, TK_COMMAND, "ls");
	dyntklist_add(tklist, TK_ARGUMENT, "-l");
	dyntklist_add(tklist, TK_ARGUMENT, "-a");
	dyntklist_add(tklist, TK_ARGUMENT, "-t");
	dyntklist_show(tklist);
	return (0);
}
```

#### dyntklist_show()

```c
void	dyntklist_show(t_dyntklist *tklist);
```

la fonction `dyntklist_show()` permet simplement d'afficher touts les éléments d'une liste dynamique.

```c
int	main(void)
{
	t_dyntklist	*tklist;

	tklist = NULL;
	tklist = dyntklist_init(tklist);
	dyntklist_add(tklist, TK_COMMAND, "ls");
	dyntklist_add(tklist, TK_ARGUMENT, "-l");
	dyntklist_add(tklist, TK_ARGUMENT, "-a");
	dyntklist_add(tklist, TK_ARGUMENT, "-t");
	dyntklist_show(tklist);
	return (0);
}
```

#### dyntklist_free()

```c
void	dyntklist_free(t_dyntklist *tklist);
```

La fonction `dyntklist_free()` permet de automatiquement libérer toute la mémoire allouée par la liste dynamique.
Afin que le méchnisme fonctionne et qu'il ne crée pas de bugs, il est important de set `t_dyntklist` à `NULL` lors de sa défintion.

```c
int	main(void)
{
	t_dyntklist	*tklist;

	tklist = NULL;
	tklist = dyntklist_init(tklist);
	dyntklist_add(tklist, TK_COMMAND, "ls");
	dyntklist_add(tklist, TK_ARGUMENT, "-l");
	dyntklist_add(tklist, TK_ARGUMENT, "-a");
	dyntklist_add(tklist, TK_ARGUMENT, "-t");
	dyntklist_show(tklist);
	dyntklist_free(tklist);
	return (0);
}
```
