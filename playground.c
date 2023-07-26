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
