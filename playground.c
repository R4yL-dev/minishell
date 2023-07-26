#include <stdio.h>
#include <unistd.h>

int main() {
	__pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		// Erreur lors du fork
		printf("Fork error.\n");
		return (1);
	}
	else if (pid == 0)
	{
		// Processus fils
		printf("Processus fils (%d) : Hello team\n", getpid());
	}
	else
	{
		// Processus parent
		printf("Processus parent (%d) : My son is %d\n", getpid(), pid);

	}
	return (0);
}
