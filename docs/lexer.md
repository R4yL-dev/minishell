# Lexer

Le rôle du lexer est de clean la ligne de commande et retourner un tableau de token

**Input** :

```bash
ls -l < input.txt | grep "file.txt" | sort > output.txt
```

**Output** :

```c
Token(type=COMMAND, value="ls")
Token(type=ARGUMENT, value="-l")
Token(type=REDIRECTION, value="<")
Token(type=FILE, value="input.txt")
Token(type=REDIRECTION, value="|")
Token(type=COMMAND, value="grep")
Token(type=ARGUMENT, value="file.txt")
Token(type=REDIRECTION, value="|")
Token(type=COMMAND, value="sort")
Token(type=REDIRECTION, value=">")
Token(type=FILE, value="output.txt")
```

## Fonctionalité initiale

Initaliement, je voudrais que que le lexer puisse enlever les éspaces en trop (pas d'éspace au début et à la fin et que un seul éspace entre les tokens).

Une fois que les épsaces en trop ne sont plus la, je veux pouvoir traiter une commande avec ces arguments.

### cleanString

```c
char	*trimAndCondenseString(const char *input)
{
	char	*trimmed;
	char	*processed

	trimmed = ft_strtrim(input, " ");
	processed = condense_string(trimmed);
	return (res);
}

char	*condense_string(const char *input)
{
	/*
	calculer la taille de input
	demander la mémoir pour la taille d'input + 1
	vérifié que la mémoire a bien été donnée
	TANT QUE input[i] n'est pas la fin de la string
		SI input[i] est un espace
			incrémenter consecutive_space
		SINON
			mettre consecutive_space à 0
		Si consecutive_space est plus petit ou égal à 1
			result[j] = input[i]
			incrémenter j
		incrémenter i
	Ajouter le char \0 à result[j]
	RETOURNER result
	*/
}
```
