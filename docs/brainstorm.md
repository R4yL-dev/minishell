# Brainstorm

## Les étapes

Bash passe par plusieurs étapes entre le moment ou l'utilsiateur entre une commande et que le résultat est affiché à l'écran.

1. **Lecture de la commande** : Bash lit la commande saisie par l'utilisateur depuis l'entrée standard (généralement le clavier).
2. **Analyse lexicale (Lexer)** : La commande est analysée par une analyseur lexical (lexer) qui découp en "token", c'est-à-dire en unités lexicales comme les mots-clés, les opérateurs, les arguments, les variables, les redirections, etc.
3. **Analyse syntaxique (Parser)** : Les tokens produits par le lexer sont analysés par un analyseur syntaxique (parser) qui crée une structure de donnlées appelée "arbre syntaxique". Cet arbre représente la structure grammaticale de la commande, définissant les relations entre les différents éléments.
4. **Expansion** : Avant l'exécution de la cmmande, Bash effectue plusieurs types d'expansion, notamment l'expansion des variables (remplacement de des noms de variables par leurs valeurs), l'expansion des commandes (remplacement des sous-commandes par leurs sorties), et l'expansion des caractères spéciaux.
5. **Évaluation des commandes** : L'arbre syntaxique est évalué pouir déterminer les actions à prendre. Cela peut inclure  l'exécution de commandes intégrées à Bash (comme `echo`, `cd`, `export`, etc.) ou d'exécutables externes.
6. **Redirection et pipe** : Les redirections (rediriger l'entrée/sortie standard vers des fichiers) et les piptes (connecter la sortie d'une commande à l'entrée d'une autre)sont généres à cette étape.
7. **Exécution des commande** : Les commandes sont exécutés, que ce soit les commandes intégrées (builtins) ou les exécutable externe.
8. **Gestion des processus** : Bash gère les processus en cours d'exécution, permettant à plusieurs commandes d'être exécutées en parallèle ou en séquence.
9. **Retour de statut** : Après l'exécution, chaque commande renvoie un statut de sortie. Une valeur 0 indique une exécution réussie, tandis que d'autres valeurs indiquent différents type d'erreurs.
10. **Affichage des résultats** : Les résultats des commandes sont affichés à l'utilisateur, généralement dans la sortie standard (terminal).

Cette liste est une simplification du fonctionnement des Bash. Elle peut donner une bonne idée de comment pourrait fonctionner notre minishell.

J'ai peur de l'arbre syntaxique de l'étape 5, il faut que je creuse plus pour commprendre.

### Le lexer

La première chose que doit faire le lexer et de nettoyer la commande reçu de l'utilisateur. Il faut enlever les espace en trop par exemple.

Une fois que l'entrée est propre, il crée une séquence de "tokens" qui représent les différentes unités lexiqcales identifiées dans la commande saisie par l'utilisateur. Chaque token contient deux informations principales : le type du token et sa valeur. Voici à quoi ressemblerait le retour du lexer pour la commande `ls -l | grep "file.txt"` :

```text
Token(type=COMMAND, valeur="ls")
Token(type=ARGUMENT, valeur="-l")
Token(type=REDIRECTION, value="|")
Token(type=COMMAND, value="grep")
Token(type=STRING, value="file.txt")
```

Dans cet exemple, chaque ligne représente un token avec son type et sa valeur. Les types de tokkens peuvent varier en fonction du langage et du contexte. Dans l'exemple ci-dessus, j'ai utilisé des types de tokens simplifés :

- `COMMAND` : Indique le nom d'une commande.
- `ARGUMENT` : Indique un argument passé à une commande.
- `REDIRECTION` : Indique l'opérateur de pipe.
- `STRING` : Indique une chaine de caractères.

Le lexer examine la commande caractère par caractrère et identifie les différentes parties en fonction des règles orédéfinies pour chaque type de token. Ces règles sont généralement basées suir des expressions régulières. Le retour du lexer peut ensuite être utilisé par l'étape suivante (analyse syntaxique) pour construire l'arbre syntaxique et déterminer la structure de la commande.

### Arbres syntaxique

L'arbre syntaxique est une structure de données hiérachique qui représenmte la strucutre grammaticale d'une commande. Chaque noeuds de l'arbre correspond à un élément syntaxique (comme une commande, un opérateur, un argument, etc.), et les relations entre les noeuds décrivent comment ces élément sont connectés.

Voici un exemple pour se faire une idées :

```bash
ls -l | grep "file.txt"
```

L'arbre syntaxique pour cette commande pourrait ressembler à quelque chose comme cela :

```text
   PIPE
  /    \
LS     GREP
 |       |
-l    "file.txt"
```

Dans cet exemple, l'arbre syntaxique montre que la commande est composée de deux parties connectées par un opérateur de pipe (`|`). La partie gauche est la commande `ls -l`, et la partie de droite est la commande `grep "file.txt"`. Chaque commande est elle-même représentée comme un noeud de l'arbre, et les arguments sont également des noeuds de l'arbre.

L'arbre syntaxique varie en fonction de la complexité de la commande et des opérations effectuées. Dans des cas plus complexes, il peut y avoir plusieurs niveaux d'imbrication avec des opérateurs différentsm des commandes imbriquées et d'autre éléments syntaxiques. Chaque élément de l'arbre a un rôle spécifique dans la séquence d'exécution de la commande.

## Ajouter le redirecteur d'entrée

Pour le moment, le programme ne peux exécuter qu'une seul commande avec un nombre n d'argument. je veux ajouter le redirecteur d'entrée afin de commencer a jouer avec les fichier et dup2().

Pour le moment, j'ai indentifier 2 manières d'utiliser le redirecteur d'entrée :

```text
grep "test" < exemple.txt
< exemple.txt grep "test"
```

J'espère qu'il n'y a pas d'autre cas que je n'ai pas identifier.

### Lexer

Pour le moment, le type `TK_REDIRECTION` existe dans l'enum, mais il n'y a aucun traitement pour détécter et taguer ce type.

Il y a deux solutions :

- Soit le premier token est `<` il est forcement suivit de sont "argument"
- Soit le premier token est autre chose (et dont une commande), suivit d'argumt jusqu'a que le token soit `<` qui sera suivit de sont argument

Bash lève une erreur dans le cas de :

```text
command <
```

Dans le cas ou il n'y a pas d'argument, Bash affiche le message d'erreur `bash: syntax error near unexpected token `newline'`. Je ne sais pas si bash détéque que le token n'a pas d'argument ou si il le détécte lors de l'exécution et qui affiche le message d'erreur au moment d ouvrir le fichier.


## Ressources

- [Let’s Build a Linux Shell — Part III](https://medium.com/swlh/lets-build-a-linux-shell-part-iii-a472c0102849)
