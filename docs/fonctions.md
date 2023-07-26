# Fonctions autorisées

## readline()

### readline() - Prototype

```c
#include <readline/readline.h>

char *readline(const char * prompt);
```

### readline() - Expliquations

La fonction `readline()` est utilisée pour lire une ligne de texte depuis l'entrée standard avec l'invite `prompt`. L'invité `prompt` est un texte optionnel qui sera  affiché à l'utilisateur avant qu'il ne saisisse sa ligne de texte. L'utilisateur peut éditer la ligne en utilisant les touches fléchées, la touche de suppression, etc. Une fois que l'utilisateur a terminé la saisie et appuie sur la touche "Entrée", la ligne saisie est retournée en tant que chaîne de caractères allouée dynamiquement.

### readline() - Exemple

```c
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

int main()
{
	char *input;

	input = readline("Entrer du texte : ");
	if (input != NULL)
	{
		printf("Vous avez saisi : %s\n", input);
		free(input);
	}
	return (0);
}
```

### readline() - Notes

- readline est un bibliothèque linux. Pour l'utiliser, en plus de l'inclure, il faut compiler avec le flag `-lreadline`. Il est possible que readline ne soit pas disponible sur votre système linux. Si c'est le cas, il devrais se trouver des le repos par défaut de votre distribution. Pour debian : `apt install libreadline-dev`.
