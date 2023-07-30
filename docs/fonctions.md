# 1. Fonctions autorisées

## 1.1. TOC

- [1. Fonctions autorisées](#1-fonctions-autorisées)
	- [1.1. TOC](#11-toc)
	- [1.2. readline()](#12-readline)
		- [1.2.1. readline() - Prototype](#121-readline---prototype)
		- [1.2.2. readline() - Explications](#122-readline---explications)
		- [1.2.3. readline() - Exemple](#123-readline---exemple)
		- [1.2.4. readline() - Notes](#124-readline---notes)
	- [1.3. rl\_clear\_history()](#13-rl_clear_history)
		- [1.3.1. rl\_clear\_history() - Prototype](#131-rl_clear_history---prototype)
		- [1.3.2. rl\_clear\_history() - Explications](#132-rl_clear_history---explications)
		- [1.3.3. rl\_clear\_history() - Exemple](#133-rl_clear_history---exemple)
	- [1.4. rl\_on\_new\_line()](#14-rl_on_new_line)
		- [1.4.1. rl\_on\_new\_line() - Prototype](#141-rl_on_new_line---prototype)
		- [1.4.2. rl\_on\_new\_line() - Explications](#142-rl_on_new_line---explications)
		- [1.4.3. rl\_on\_new\_line() - Exemple](#143-rl_on_new_line---exemple)
		- [1.4.4. rl\_on\_new\_line() - Notes](#144-rl_on_new_line---notes)
	- [1.5. rl\_replace\_line()](#15-rl_replace_line)
		- [1.5.1. rl\_replace\_line() - Prototype](#151-rl_replace_line---prototype)
		- [1.5.2. rl\_replace\_line() - Explications](#152-rl_replace_line---explications)
		- [1.5.3. rl\_replace\_line() - Exemple](#153-rl_replace_line---exemple)
		- [1.5.4. rl\_replace\_line() - Notes](#154-rl_replace_line---notes)
	- [1.6. rl\_redisplay()](#16-rl_redisplay)
		- [1.6.1. rl\_redisplay() - Prototype](#161-rl_redisplay---prototype)
		- [1.6.2. rl\_redisplay() - Explications](#162-rl_redisplay---explications)
		- [1.6.3. rl\_redisplay() - Exemple](#163-rl_redisplay---exemple)
		- [1.6.4. rl\_redisplay() - Notes](#164-rl_redisplay---notes)
	- [1.7. add\_history()](#17-add_history)
		- [1.7.1. add\_history() - Prototype](#171-add_history---prototype)
		- [1.7.2. add\_history() - Explications](#172-add_history---explications)
		- [1.7.3. add\_history() - Exemple](#173-add_history---exemple)
	- [1.8. printf()](#18-printf)
	- [1.9. malloc()](#19-malloc)
	- [1.10. free()](#110-free)
	- [1.11. write()](#111-write)
	- [1.12. access()](#112-access)
		- [1.12.1. access() - Prototype](#1121-access---prototype)
		- [1.12.2. access() - Explications](#1122-access---explications)
		- [1.12.3. access() - Exemple](#1123-access---exemple)
	- [1.13. open()](#113-open)
	- [1.14. read()](#114-read)
	- [1.15. close()](#115-close)
	- [1.16. fork()](#116-fork)
		- [1.16.1. fork() - Prototype](#1161-fork---prototype)
		- [1.16.2. fork() - Explications](#1162-fork---explications)
		- [1.16.3. fork() - Exemple](#1163-fork---exemple)
	- [1.17. wait()](#117-wait)
		- [1.17.1. wait() - Prototype](#1171-wait---prototype)
		- [1.17.2. wait() - Explications](#1172-wait---explications)
		- [1.17.3. wait() - Exemple](#1173-wait---exemple)
	- [1.18. waitpid()](#118-waitpid)
		- [1.18.1. waitpid() - Prototype](#1181-waitpid---prototype)
		- [1.18.2. waitpid() - Explications](#1182-waitpid---explications)
		- [1.18.3. waitpid() - Exemple](#1183-waitpid---exemple)
		- [1.18.4. waitpid() - Notes](#1184-waitpid---notes)
	- [1.19. wait3()](#119-wait3)
		- [1.19.1. wait3() - Prototype](#1191-wait3---prototype)
		- [1.19.2. wait3() - Explications](#1192-wait3---explications)
		- [1.19.3. wait3() - Exemple](#1193-wait3---exemple)
		- [1.19.4. wait3() - Notes](#1194-wait3---notes)
	- [1.20. wait4()](#120-wait4)
		- [1.20.1. wait4() - Prototype](#1201-wait4---prototype)
		- [1.20.2. wait4() - Explications](#1202-wait4---explications)
		- [1.20.3. wait4() - Exemple](#1203-wait4---exemple)
		- [1.20.4. wait4() - Notes](#1204-wait4---notes)
	- [1.21. signal()](#121-signal)
		- [1.21.1. signal() - Prototype](#1211-signal---prototype)
		- [1.21.2. signal() - Explications](#1212-signal---explications)
		- [1.21.3. signal() - Exemple](#1213-signal---exemple)
		- [1.21.4. signal() - Notes](#1214-signal---notes)
	- [1.22. sigaction()](#122-sigaction)
		- [1.22.1. sigaction() - Prototype](#1221-sigaction---prototype)
		- [1.22.2. sigaction() - Explications](#1222-sigaction---explications)
		- [1.22.3. sigaction() - Exemple](#1223-sigaction---exemple)
		- [1.22.4. sigaction() - Notes](#1224-sigaction---notes)
	- [1.23. sigemptyset()](#123-sigemptyset)
		- [1.23.1. sigemptyset() - Prototype](#1231-sigemptyset---prototype)
		- [1.23.2. sigemptyset() - Explications](#1232-sigemptyset---explications)
		- [1.23.3. sigemptyset() - Exemple](#1233-sigemptyset---exemple)
		- [1.23.4. sigemptyset() - Notes](#1234-sigemptyset---notes)
	- [1.24. sigaddset()](#124-sigaddset)
		- [1.24.1. sigaddset() - Prototype](#1241-sigaddset---prototype)
		- [1.24.2. sigaddset() - Explications](#1242-sigaddset---explications)
		- [1.24.3. sigaddset() - Exemple](#1243-sigaddset---exemple)
	- [1.25. kill()](#125-kill)
		- [1.25.1. kill() - Prototype](#1251-kill---prototype)
		- [1.25.2. kill() - Explications](#1252-kill---explications)
		- [1.25.3. kill() - Exemple](#1253-kill---exemple)
	- [1.26. exit()](#126-exit)
	- [1.27. getcwd()](#127-getcwd)
		- [1.27.1. getcwd() - Prototype](#1271-getcwd---prototype)
		- [1.27.2. getcwd() - Explications](#1272-getcwd---explications)
		- [1.27.3. getcwd() - Exemple](#1273-getcwd---exemple)
	- [1.28. chdir()](#128-chdir)
		- [1.28.1. chdir() - Prototype](#1281-chdir---prototype)
		- [1.28.2. chdir() - Explications](#1282-chdir---explications)
		- [1.28.3. chdir() - Exemple](#1283-chdir---exemple)
	- [1.29. stat()](#129-stat)
		- [1.29.1. stat() - Prototype](#1291-stat---prototype)
		- [1.29.2. stat() - Explications](#1292-stat---explications)
		- [1.29.3. stat() - Exemple](#1293-stat---exemple)
	- [1.30. lstat()](#130-lstat)
		- [1.30.1. lstat() - Prototype](#1301-lstat---prototype)
		- [1.30.2. lstat() - Explications](#1302-lstat---explications)
		- [1.30.3. lstat() - Exemple](#1303-lstat---exemple)
	- [1.31. fstat()](#131-fstat)
		- [1.31.1. fstat() - Prototype](#1311-fstat---prototype)
		- [1.31.2. fstat() - Explications](#1312-fstat---explications)
		- [1.31.3. fstat() - Exemple](#1313-fstat---exemple)
	- [1.32. unlink()](#132-unlink)
		- [1.32.1. unlink() - Prototype](#1321-unlink---prototype)
		- [1.32.2. unlink() - Explications](#1322-unlink---explications)
		- [1.32.3. unlink() - Exemple](#1323-unlink---exemple)
	- [1.33. execve()](#133-execve)
		- [1.33.1. execve() - Prototype](#1331-execve---prototype)
		- [1.33.2. execve() - Explications](#1332-execve---explications)
		- [1.33.3. execve() - Exemple](#1333-execve---exemple)
	- [1.34. dup()](#134-dup)
		- [1.34.1. dup() - Prototype](#1341-dup---prototype)
		- [1.34.2. dup() - Explications](#1342-dup---explications)
		- [1.34.3. dup() - Exemple](#1343-dup---exemple)
	- [1.35. dup2()](#135-dup2)
		- [1.35.1. dup2() - Prototype](#1351-dup2---prototype)
		- [1.35.2. dup2() - Explications](#1352-dup2---explications)
		- [1.35.3. dup2() - Exemple](#1353-dup2---exemple)
	- [1.36. pipe()](#136-pipe)
		- [1.36.1. pipe() - Prototype](#1361-pipe---prototype)
		- [1.36.2. pipe() - Explications](#1362-pipe---explications)
		- [1.36.3. pipe() - Exemple](#1363-pipe---exemple)
	- [1.37. opendir()](#137-opendir)
		- [1.37.1. opendir() - Prototype](#1371-opendir---prototype)
		- [1.37.2. opendir() - Explications](#1372-opendir---explications)
		- [1.37.3. opendir() - Exemple](#1373-opendir---exemple)
	- [1.38. readdir()](#138-readdir)
		- [1.38.1. readdir() - Prototype](#1381-readdir---prototype)
		- [1.38.2. readdir() - Explications](#1382-readdir---explications)
		- [1.38.3. readdir() - Exemple](#1383-readdir---exemple)
	- [1.39. closedir()](#139-closedir)
		- [1.39.1. closedir() - Prototype](#1391-closedir---prototype)
		- [1.39.2. closedir() - Explications](#1392-closedir---explications)
	- [1.40. strerror()](#140-strerror)
		- [1.40.1. strerror() - Prototype](#1401-strerror---prototype)
		- [1.40.2. strerror() - Explications](#1402-strerror---explications)
		- [1.40.3. strerror() - Exemple](#1403-strerror---exemple)
	- [1.41. perror()](#141-perror)
		- [1.41.1. perror() - Prototype](#1411-perror---prototype)
		- [1.41.2. perror() - Explications](#1412-perror---explications)
		- [1.41.3. perror() - Exemple](#1413-perror---exemple)
	- [1.42. isatty()](#142-isatty)
		- [1.42.1. isatty() - Prototype](#1421-isatty---prototype)
		- [1.42.2. isatty() - Explications](#1422-isatty---explications)
		- [1.42.3. isatty() - Exemple](#1423-isatty---exemple)
	- [1.43. ttyname()](#143-ttyname)
		- [1.43.1. ttyname() - Prototype](#1431-ttyname---prototype)
		- [1.43.2. ttyname() - Explications](#1432-ttyname---explications)
		- [1.43.3. ttyname() - Exemple](#1433-ttyname---exemple)
	- [1.44. ttyslot()](#144-ttyslot)
		- [1.44.1. ttyslot() - Prototype](#1441-ttyslot---prototype)
		- [1.44.2. ttyslot() - Explications](#1442-ttyslot---explications)
		- [1.44.3. ttyslot() - Exemple](#1443-ttyslot---exemple)
		- [1.44.4. ttyslot() - Notes](#1444-ttyslot---notes)
	- [1.45. ioctl()](#145-ioctl)
		- [1.45.1. ioctl() - Prototype](#1451-ioctl---prototype)
		- [1.45.2. ioctl() - Explications](#1452-ioctl---explications)
		- [1.45.3. ioctl() - Exemple](#1453-ioctl---exemple)
		- [1.45.4. ioctl() - Notes](#1454-ioctl---notes)
	- [1.46. getenv()](#146-getenv)
		- [1.46.1. getenv() - Prototype](#1461-getenv---prototype)
		- [1.46.2. getenv() - Explications](#1462-getenv---explications)
		- [1.46.3. getenv() - Exemple](#1463-getenv---exemple)
	- [1.47. tcsetattr()](#147-tcsetattr)
		- [1.47.1. tcsetattr() - Prototype](#1471-tcsetattr---prototype)
		- [1.47.2. tcsetattr() - Explications](#1472-tcsetattr---explications)
		- [1.47.3. tcsetattr() - Exemple](#1473-tcsetattr---exemple)
		- [1.47.4. tcsetattr() - Notes](#1474-tcsetattr---notes)
	- [1.48. tcgetattr()](#148-tcgetattr)
		- [1.48.1. tcgetattr() - Prototype](#1481-tcgetattr---prototype)
		- [1.48.2. tcgetattr() - Explications](#1482-tcgetattr---explications)
		- [1.48.3. tcgetattr() - Exemple](#1483-tcgetattr---exemple)
	- [1.49. tgetent()](#149-tgetent)
		- [1.49.1. tgetent() - Prototype](#1491-tgetent---prototype)
		- [1.49.2. tgetent() - Explications](#1492-tgetent---explications)
		- [1.49.3. tgetent() - Exemple](#1493-tgetent---exemple)
		- [1.49.4. tgetent() - Notes](#1494-tgetent---notes)
	- [1.50. tgetflag()](#150-tgetflag)
		- [1.50.1. tgetflag() - Prototype](#1501-tgetflag---prototype)
		- [1.50.2. tgetflag() - Explications](#1502-tgetflag---explications)
		- [1.50.3. tgetflag() - Exemple](#1503-tgetflag---exemple)
	- [1.51. tgetnum()](#151-tgetnum)
		- [1.51.1. tgetnum() - Prototype](#1511-tgetnum---prototype)
		- [1.51.2. tgetnum() - Explication](#1512-tgetnum---explication)
		- [1.51.3. tgetnum() - Exemple](#1513-tgetnum---exemple)
	- [1.52. tgetstr()](#152-tgetstr)
		- [1.52.1. tgetstr() - Prototype](#1521-tgetstr---prototype)
		- [1.52.2. tgetstr() - Explications](#1522-tgetstr---explications)
		- [1.52.3. tgetstr() - Exemple](#1523-tgetstr---exemple)
		- [1.52.4. tgetstr() - Notes](#1524-tgetstr---notes)
	- [1.53. tgoto()](#153-tgoto)
		- [1.53.1. tgoto() - Prototype](#1531-tgoto---prototype)
		- [1.53.2. tgoto() - Explications](#1532-tgoto---explications)
		- [1.53.3. tgoto() - Exemple](#1533-tgoto---exemple)
	- [1.54. tputs()](#154-tputs)
		- [1.54.1. tputs() - Prototype](#1541-tputs---prototype)
		- [1.54.2. tputs() - Explications](#1542-tputs---explications)
		- [1.54.3. tputs() - Exemple](#1543-tputs---exemple)

## 1.2. readline()

### 1.2.1. readline() - Prototype

```c
#include <readline/readline.h>

char *readline(const char * prompt);
```

### 1.2.2. readline() - Explications

La fonction `readline()` est utilisée pour lire une ligne de texte depuis l'entrée standard avec l'invite `prompt`. L'invité `prompt` est un texte optionnel qui sera  affiché à l'utilisateur avant qu'il ne saisisse sa ligne de texte. L'utilisateur peut éditer la ligne en utilisant les touches fléchées, la touche de suppression, etc. Une fois que l'utilisateur a terminé la saisie et appuie sur la touche "Entrée", la ligne saisie est retournée en tant que chaîne de caractères allouée dynamiquement.

### 1.2.3. readline() - Exemple

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

### 1.2.4. readline() - Notes

- readline est un bibliothèque linux. Pour l'utiliser, en plus de l'inclure, il faut compiler avec le flag `-lreadline`. Il est possible que readline ne soit pas disponible sur votre système linux. Si c'est le cas, il devrais se trouver des le repos par défaut de votre distribution. Pour debian : `apt install libreadline-dev`.

## 1.3. rl_clear_history()

### 1.3.1. rl_clear_history() - Prototype

```c
#include <readline/history.h>

void rl_clear_history();
```

### 1.3.2. rl_clear_history() - Explications

La fonction `rl_clear_history()` est utilisée pour effacer toutes les lignes de texte présente dans l'historique de readline.

### 1.3.3. rl_clear_history() - Exemple

```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	HIST_ENTRY **hist;
	int i = 0;

	// Saisie de quelques lignes de texte et ajout à l'historique
	add_history("ls -la /usr");
	add_history("pwd");
	add_history("less /etc/hosts");

	// Générer la un tableau contenant tous l'historique
	hist = history_list();

	// Suppression de l'historique
	rl_clear_history();

	// Affichage de l'historique
	while (hist && hist[i])
	{
		printf("%s\n", hist[i]->line);
		i++;
	}
	return 0;
}
```

```text

```

## 1.4. rl_on_new_line()

### 1.4.1. rl_on_new_line() - Prototype

```c
#include <readline/readline.h>

void rl_on_new_line(void);
```

### 1.4.2. rl_on_new_line() - Explications


### 1.4.3. rl_on_new_line() - Exemple

### 1.4.4. rl_on_new_line() - Notes

Je ne comprendre pas comment utilsier cette fonction.

## 1.5. rl_replace_line()

### 1.5.1. rl_replace_line() - Prototype

```c
#include <readline/readline.h>

int rl_replace_line(const char *line, int clear_undo);
```

### 1.5.2. rl_replace_line() - Explications

### 1.5.3. rl_replace_line() - Exemple

### 1.5.4. rl_replace_line() - Notes

Je ne comprendre pas comment utilsier cette fonction.

## 1.6. rl_redisplay()

### 1.6.1. rl_redisplay() - Prototype

### 1.6.2. rl_redisplay() - Explications

### 1.6.3. rl_redisplay() - Exemple

### 1.6.4. rl_redisplay() - Notes

Je ne comprendre pas comment utilsier cette fonction.

## 1.7. add_history()

### 1.7.1. add_history() - Prototype

```c
#include <readline/history.h>

void add_history(const char *line);
```

### 1.7.2. add_history() - Explications

La fonction `add_history()` prend en paramètre une chaîne de caractères `line`, qui représente la ligne de texte à ajouter à l'historique. Cette fonction ajoute la logne spécifiée à l'historique interne de readline, qui conserve un enregistrement des lignes saisies par l 'utilisateur. L'historique peut être utilisé ensuite pour permettre à l'utilisateur de naviguer dans ses saisies précédentes à l'aide des touches fléchée (haut et bas) ou en utilisant d'autres commandes de navigation d'historique fournies par readline.

Il est important de noter que pour utiliser l'historique avec readline, tu dois appeler `add_history()` chaque fois que l'utilisateur saisit une nouvelle ligne de texte que tu souhaites conserver dans l'historique.

### 1.7.3. add_history() - Exemple

```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	HIST_ENTRY **hist;
	int i = 0;

	// Saisie de quelques lignes de texte et ajout à l'historique
	add_history("ls -la /usr");
	add_history("pwd");
	add_history("less /etc/hosts");

	// Générer la un tableau contenant tous l'historique
	hist = history_list();

	// Afficher l'historique
	while (hist && hist[i])
	{
		printf("%s\n", hist[i]->line);
		i++;
	}
	return 0;
}
```

```text
ls -la /usr
pwd
less /etc/hosts
```

## 1.8. printf()

Tu connais déjà `printf()` !!

## 1.9. malloc()

Tu connais déjà `malloc()` !!

## 1.10. free()

Tu connais déjà `free()` !!

## 1.11. write()

Tu connais déjà `write()` !!

## 1.12. access()

### 1.12.1. access() - Prototype

```c
#include <unistd.h>

int access(const char *pathname, int mode);
```

### 1.12.2. access() - Explications

La fonction `access()` prend deux arguments : `pathname`, qui est une chaîne de caractères représentant le chamin d'accès au fichier ou au répértoire que l'on veut vérifier, et `mode`, qui est un entier indiquant les opérations que l'on souhaite vérifier.

Le paramètre `mode` peut prendre différentes valeurs eour vérifier différents types de permission , et il est spécifié en utilisant des constantes prédéfinies (macros) damns le fichier d'en-tête `unistd.h`. Voici quelques valeurs possibles pour `mode` :

- `F_OK` : Vérifie simplement si le fichier existe.
- `R_OK` : Vérifie si l'utilsiateur a le droit de lire le fichier.
- `W_OK` : Vérifie si l'utilisateur à le droit d'écrire dans le fichier.
- `X_OK` : Vérifie si l'utilisateur a le droit d'exécuter (si le fichier est un programme exécutable).

La fonction `access()` renverra `0` si l'accès aux opérations spécifiées est autorisé, et `-1` en cas d'erreur, avec `errno` définit pour indiquer la nature de l'erreur.

### 1.12.3. access() - Exemple

```c
#include <stdio.h>
#include <unistd.h>

int main() {
	const char *file = "/home/luca/Git/minishell/minishell";

	if (access(file, F_OK) == 0)
		printf("Le fichier existe\n");
	else
		printf("Le fichier n'existe pas\n");
	return 0;
}
```

```text
Le fichier existe
```

## 1.13. open()

Tu connais déjà `open()` !!

## 1.14. read()

Tu connais déjà `read()` !!

## 1.15. close()

Tu connais déjà `close()` !!

## 1.16. fork()

### 1.16.1. fork() - Prototype

```c
#include <unistd.h>

pid_t fork(void);
```

### 1.16.2. fork() - Explications

Lorsque tu appelles `fork()`, le système d'exploitation crée une copie identique du processus appelant, à l'exception de certaines valeurs (comme le PID, l'identifiant de processus). Le nouveau processus, c'est à dire le processus fils, commence à s'exécuter à la suite de l'appel à `fork()`.

Après l'appel à `fork()`, le processus parent et le processus fils partagent initalement la même image mémoire, les mêmes descripteur de fichiers ouverts, les mêmes attributs de processus, etc. Cependant, les modifications ultérieurs effectuées par l'un des processus n'affectent pas l'autre processus. Cela signifie que les deux processus continuenet de s'exécuter indépendament l'un de l'autre.

La valeur de retour de `fork()` est différente pour chaque processus :

- Dans le processus parent, `fork()` renvoie le PID du processus fils.
- Dans le processus fils, `fork()` renvoie 0 pour indiquer qu'il est le processus fils.

Dans le cas ou `fork()` échoue, il renverra -1, indiquant qu'aucun processus fils n'a été créer. en cas d'échec, l'erreur peut être consultée en utilisant la variable globale `errno`.

### 1.16.3. fork() - Exemple

```c
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
```

```text
Processus parent (54615) : My son is 54616
Processus fils (54616) : Hello team
```

## 1.17. wait()

### 1.17.1. wait() - Prototype

```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status);
```

### 1.17.2. wait() - Explications

La fonction `wait()` attend qu'un processus fils se termine, et elle bloque l'exécution du processus parent jusqu'a ce que cela se produise. Elle prend un  pointeur vers un entier `status` en paramètre, qui est utilisé pour récupérer le status de sortie du processus fils. Ce statut contient des informations sur la manière dont le processus fils, telles que le code de retour du processus fils et s il s est terminé normalement ou à cause d un signal.

La valeur de retour de `wait()` est le pid du processus fils qui s'est terminé, ou -1 s'il y a une erreur (par exemple, s'il n'y pas de processus fils à attendre).

Il est important de noter que si le processus parent a plusieurs processus fils, `wait()` attendra uniquement la fin d'un processus fils à la fois. Pour attendre la fin de tous les priocessus fils, il peut être nécessaire d'appeler `wait()` plusieurs fois.

### 1.17.3. wait() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	__pid_t pid;
	__pid_t child_pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		// Erreur lors du fork
		printf("Fork error.\n");
		return (1);
	}
	else if (pid == 0)
	{
		printf("Processus fils (%d) : Hello team\n", getpid());
		// Simule une tache qui dure 3 secondes
		sleep(3);
	}
	else
	{
		printf("Processus parent (%d) : Mon fils est %d\n", getpid(), pid);
		// Attendre la fin du processus fils
		child_pid = wait(&status);
		if (child_pid == -1)
			return (2);
		else
		{
			printf("Valeur de retour de wait() : %d\n", child_pid);
			printf("Valeur de status : %d\n", status);
		}
	}
	return (0);
}
```

```text
Processus parent (2588) : Mon fils est 2589
Processus fils (2589) : Hello team
Valeur de retour de wait() : 2589
Valeur de status : 0
```

Dans cette exemple, je cree un processus fils qui attend durant 3 secondes afin de simuler une tâche. Le processus parent attend durant se temps et une fois terminer, vérifie que l'opération c'est bien déroulée (child_pid == -1). Si tout c'est bien passé, nous affichons `child_pid` afin de constater que la valeur de retour de `wait()` est bien le pid du processus fils. Nous affichons aussi `status` qui vaut `0` si le `wait()` c'est bien déroulé.

## 1.18. waitpid()

### 1.18.1. waitpid() - Prototype

```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *status, int options);
```

### 1.18.2. waitpid() - Explications

la fonction `waitpid()` prend trois arguments :

- `pid` : L'id du processus fils que le processus parent souhaite attendre. Il peut prendre différentes valeur :
  - `> 0` : Attendre le processus avec le PID spécifié.
  - `0` : Attendre n'importe quel processus fils du groupe de processus parent.
  - `-1` : Attendre n'importe quel processus fils, semblable à `wait()`.
  - `< -1` : Attendre n'importe quel processus fils dont le groupe de processus est égal à la valeur absolue de `pid`.
- `status` : Un pointeur vers un entier ou le status de sortie du processus fils sera stocké. Comme pour `wait()`, ce status contient des informations sur la manière dont le processus fils s'est terminé.
- `options` : Des options supplémentaires pour spécifier le compertement d'attente. Tu peux utiliser `0` pour attendre le processus fils de manière normale ou utiliser des options spécifiques, telles que `WNOHANG` pour effectuer une attente non bloquante.

La valeur de retour de `waitpid()` est le PID du processus fils qui s'est terminé, ou :

- `-1` en cas d'erreur (pas de processus fils à attendre ou une erreur s'est produite).
- `0` si l'option `WNOHANG` est utilisée et que le processus fils spécifié n'est pas encore terminé.

Il est important de noté que `waitpid()` est plus souple que `wait()` et offre des possibilités supplémentaires pour la gestion des processus fils dans des situations spécifiques.

### 1.18.3. waitpid() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	__pid_t pid;
	__pid_t child_pid;
	int status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		printf("Processus fils (%d) : Simule du travail durant 3 secondes\n", getpid());
		sleep(3);
	}
	else
	{
		printf("Processus parent (%d) : Mon fils est %d\n", getpid(), pid);
		// Attendre la fin du processus fils spécifié dans la variable pid
		child_pid = waitpid(pid, &status, 0);
		if (child_pid == -1)
			return (2);
		else
		{
			printf("Valeur de retour de waitpid() : %d\n", child_pid);
			printf("Valeur de status : %d\n", status);
		}
	}
	return (0);
}
```

```text
Processus parent (6696) : Mon fils est 6697
Processus fils (6697) : Simule du travail durant 3 secondes
Valeur de retour de waitpid() : 6697
Valeur de status : 0
```

### 1.18.4. waitpid() - Notes

## 1.19. wait3()

### 1.19.1. wait3() - Prototype

### 1.19.2. wait3() - Explications

### 1.19.3. wait3() - Exemple

### 1.19.4. wait3() - Notes

Je n'ai pas encore tout bien compris, mais je crois que `wait3()` est un implémentation de `wait()` spécifique à certains systèmes UNIX. Peux être MOSX ?

## 1.20. wait4()

### 1.20.1. wait4() - Prototype

### 1.20.2. wait4() - Explications

### 1.20.3. wait4() - Exemple

### 1.20.4. wait4() - Notes

Je n'ai pas encore tout bien compris, mais je crois que `wait4()` est un implémentation de `wait()` spécifique à certains systèmes UNIX. Peux être MOSX ?

## 1.21. signal()

### 1.21.1. signal() - Prototype

```c
#include <signal.h>

void (*signal(int signum, void (*handler)(int)))(int);
```

### 1.21.2. signal() - Explications

La fonction `signal()` prend deux arguments :

- `signum` : C'est l'identifiant du signal que tu souhaites traiter. Les signaux sont identifiés par des constates prédéfinies dans le fichier d'en-tête `<signal.h>`, comme `SIGINT` pour le signal d'interruption (généralement envoyé lorsqu'un utilisateur appuie sur Ctrl+C), `SIGTERM` pour le signal de terminaison, `SIGUSR1` et `SIGUSR2` pour des signaux personnalisés, etc.
- `handler` : C'est un pointeur vers la fonction qui sera exécutée lorsque le signal spécifié est reçu. La fonction de gestion des signaux doit avoir le format `void handler(int signum)`, ou `signum` est l'identifiant du signal reçu.

La fonction `signal()` renvoie le pointeur vers l'ancien gestionnaire de signal, ou `SIG_ERR` en cas d'erreur.

### 1.21.3. signal() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// Fonction qui sera exécutée lors SIGINT est reçu
// Il ne faut pas oublier de exit car sinon nous sommes bloquer dans le programme
void handler_SIGINT(int signum)
{
	printf("\nSIGINT reçu ! (%d)\n", signum);
	printf("Quit...\n");
	_exit(0);
}

int main()
{
	// Définition du handler personnalisé pour le signal SIGINT
	if (signal(SIGINT, handler_SIGINT) == SIG_ERR)
	{
		// Erreur de signal
		printf("Erreur lors de la définition du handler de SIGINT\n");
		return (1);
	}
	printf("Handler pour SIGINT définit\nAppuyez sur Ctrl+C\n");
	// Boucle infinie pour attendre le Ctrl+C
	while(1)
	{
		sleep(1);
	}
	return (0);
}
```

```text
Handler pour SIGINT définit
Appuyez sur Ctrl+C
^C
SIGINT reçu ! (2)
Quit...
```

Dance cet exemple, nous utilisons `signal()` pour définir un handler personnalisé (`handler_SIGINT()`) pour le signal `SIGINT`. Lorsque l'utilisateur appuie sur Ctrl+C pour envoyer le signal `SIGINT`, le handler est exécuté, le message "SIGINT reçu ! (2)" est afficher et le programme quitte.

### 1.21.4. signal() - Notes

Il est important de noter que la fonction `signal()` est considérée comme obsolète dans certain contextes, car elle présente certains problèmes d'interprétation des signaux dans les environnements multi-thread. Il est recommandé d'utiliser la fonction `sigaction()` à la place, car elle offre une interface plus robuste pour la gestion des signaux.

## 1.22. sigaction()

### 1.22.1. sigaction() - Prototype

```c
#include <signal.h>

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

### 1.22.2. sigaction() - Explications

La fonction `sigaction()` prend trois arguments :

- `signum` : C'est l'identifiant du signal que tu souhaites traiter. Les signaux sont identifiés par des constantes prédéfinies dans le fichier d'en-tête `<signal.h>`, comme `SIGINT` pour le signal d'interruption (généralement envoyé avec Ctrl+C), `SIGTERM` pour le signal de terminaison, `SIGUSR1` et `SIGUSR2` pour des signaux personnalisés, etc.
- `act` : Un pointeur vers une structure `struct sigaction` qui spécifie le nouveau handler de signal à définir. La strucutre `struct sigaction` a la forme suivante :
```c
struct sigaction
{
	void (*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags
	void (*sa_sigaction)(int, siginfo_t *, void *);
};
```
-
  - `sa_handler` : Un pointeur vers une fonction handler de signal, de la même manière que la fonction `signal()`. La fonction doit avoir la signature `void handler(int signum)`, ou `signum` est l'identifiant du signal reçu.
  - `sa_mask` : Un ensemble de signaux supplémentaire à bloquer pendant que le handler de signal est en cours d'exécution. Cela permet d'éviter la récursivité involontaire si le même signal est reçu pendant que le ghandler est déjà en cours d'exécution.
  - `sa_flags` : Drapeaux qui contrôlent le comportement du handler de signal. Par exemple, tu peux utiliser le drapeau `SA_RESTART` pour redémarrer les appels système interrompus par le signal plutôt que de les échouer avec `EINTR`.
  - `sa_sigaction` : Un pointeur vers une fonction alternative de handler de signal. Cette fonction prend trois arguments et peut fournir des informations supplémentaire sur le signal reçu à l'aide de la structure `siginfo_t`. Ce champ est utilisé lorsque `sa_flag` inclut le drapeau `SA_SIGINFO`, sinon, `sa_handler` est utilisé.
- `oldact` : Un pointeur vers un structure `struct sigaction` ou le handler de signal précédent sera stocké, si néscessaire.

La fonction `sigaction()` renvoie `0` en cas de succèsm ou `-1` en ac d'erreur. En cas d'erreur, tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.22.3. sigaction() - Exemple

```c
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// Fonction qui sera exécutée lors SIGINT est reçu
// Il ne faut pas oublier de exit car sinon nous sommes bloquer dans le programme
void handler_SIGINT(int signum)
{
	static int count = 0;
	(void) signum;

	count++;
	printf("\nSIGINT reçu ! (count = %d)\n", count);
	if (count == 10)
	{
		printf("Quit...\n");
		_exit(0);
	}
}

int main()
{
	struct sigaction new_action;

	// Définition du nouveau handler
	new_action.sa_handler = handler_SIGINT;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;

	// Remplacer l'ancien handler par le nouveau
	if (sigaction(SIGINT, &new_action, NULL) == -1)
	{
		// Erreur de signal
		printf("Erreur lors de la définition du handler de SIGINT\n");
		return (1);
	}
	printf("Handler pour SIGINT définit\nAppuyez sur Ctrl+C\n");
	printf("Pour quitter, appuier 10 fois Ctrl+C\n");
	// Boucle infinie pour attendre les Ctrl+C
	while(1)
	{
		sleep(1);
	}
	return (0);
}
```

```text
Handler pour SIGINT définit
Appuyez sur Ctrl+C
Pour quitter, appuier 10 fois Ctrl+C
^C
SIGINT reçu ! (count = 1)
^C
SIGINT reçu ! (count = 2)
^C
SIGINT reçu ! (count = 3)
^C
SIGINT reçu ! (count = 4)
^C
SIGINT reçu ! (count = 5)
^C
SIGINT reçu ! (count = 6)
^C
SIGINT reçu ! (count = 7)
^C
SIGINT reçu ! (count = 8)
^C
SIGINT reçu ! (count = 9)
^C
SIGINT reçu ! (count = 10)
Quit...
```

### 1.22.4. sigaction() - Notes

Pour que cela fonctionne, il m'a fallu ajouter `-std=gnu89` lors de la compilation.

## 1.23. sigemptyset()

### 1.23.1. sigemptyset() - Prototype

```c
#include <signal.h>

int sigemptyset(sigset_t *set);
```

### 1.23.2. sigemptyset() - Explications

La fonction `sigemptyset()` prend un pointeur vers un ensemble de signaux `set` en paramètre et initalise cet ensemble en le vidant, c'est à dire qu'aucun signal ne sera inclus dans l'ensemble de signaux.

Il est important de noter que la fonction `sigemptyset()` ne renvoie pas de valeur significative en elle-même. Elle renvoie `0` en cas de succès, et `-1` en cas d'erreur.

### 1.23.3. sigemptyset() - Exemple

```c
#include <stdio.h>
#include <signal.h>

int main()
{
	sigset_t set;

	// Initalisation du set
	if (sigemptyset(&set) == -1)
	{
		printf("Erreur lors de l'initalisation du set\n");
		return (1);
	}
	// Ajouter le signal SIGINT au set
	if (sigaddset(&set, SIGINT) == -1)
	{
		printf("Erreur lors de l'ajout de SIGINT dans le set\n");
		return (2);
	}
	// Vérifier que SIGINT est inclus dans le set
	if (sigismember(&set, SIGINT) == 1)
		printf("SIGINT est inclus dans le set\n");
	else
		printf("SIGINT n'est pas inclus dans le set\n");
	// On vide le set
	if (sigemptyset(&set) == -1)
	{
		printf("Erreur lors du vidage du set\n");
		return (3);
	}
	// Vérifier que SIGINT n'est plus dans le set
	if (sigismember(&set, SIGINT) == 1)
		printf("SIGINT est inclus dans le set\n");
	else
		printf("SIGINT n'est pas inclus dans le set\n");
	return (0);
}
```

```text
SIGINT est inclus dans le set
SIGINT n'est pas inclus dans le set
```

Dans cet exemple, nous utilisons `sigemptyset()` pour initaliser le set, puis `sigaddset()` pour ajouter le signal `SIGINT` dans le set. Ensuite, nous utilisons `sigismember()` pour vérifier que `SIGINT` et bien dans le set. Finalement, nous ré-utilisons `sigemptyset()` pour vider le set et constater avec `sigismember()` que le set est bien vide.

### 1.23.4. sigemptyset() - Notes

Il faut dans tous les cas commencer par utiliser `sigemptyset()` afin d'initaliser le set.

## 1.24. sigaddset()

### 1.24.1. sigaddset() - Prototype

```c
#include <signal.h>

int sigaddset(sigset_t *set, int signum);
```

### 1.24.2. sigaddset() - Explications

La fonction `sigaddset()` prend deux paramètres :

- `set` : Un pointeur vers l'ensemble de signaux (`sigset_t`) auquel tu veux ajouter un signal.
- `signum` : L'identifiant du signal que tu souhaite ajouter au set.

La fonction `sigaddset()` retourne `0` en cas de succès et `-1` en cas d'erreur.

### 1.24.3. sigaddset() - Exemple

```c
#include <stdio.h>
#include <signal.h>

int main()
{
	sigset_t set;

	// Initalisation du set
	if (sigemptyset(&set) == -1)
	{
		printf("Erreur lors de l'initalisation du set\n");
		return (1);
	}
	// Ajouter le signal SIGINT au set
	if (sigaddset(&set, SIGINT) == -1)
	{
		printf("Erreur lors de l'ajout de SIGINT dans le set\n");
		return (2);
	}
	// Vérifier que SIGINT est inclus dans le set
	if (sigismember(&set, SIGINT) == 1)
		printf("SIGINT est inclus dans le set\n");
	else
		printf("SIGINT n'est pas inclus dans le set\n");
	return (0);
}
```

```text
SIGINT est inclus dans le set
```

## 1.25. kill()

### 1.25.1. kill() - Prototype

```c
#include <signal.h>

int kill(pid_t, int sig);
```

### 1.25.2. kill() - Explications

La fonction `kill()` prend deux arguments :

- `pid` : L'identifiant de processus (PID) du processus auquel tu veux envoyer le signal. Il peut prendre différentes valeur :
  - `> 0` : Le signal est envoyé au processus avec le PID spécifié.
  - `0` : Le signal est envoyé à tous les processus du même groupe de processus que celui de l'appelant.
  - `-1` : Le signal est envoyé à tous les processus du même utilsateur que celui de l'appelant (à l'exception des processus pour lesquels l'appelant n'a pas leapermission d'envoyer des signaux).
  - `< -1` : Le signal est envoyé à tous les processus du groupe de processus indiqué par la valeur absolue de `pid`.
- `sig` : L'identifiant du signal que tu souhaites envoyer. Les signaux sont identifié par des constantes prédéfinies dans le fichier d'en-tête `<signal.h>`, telles que `SIGINT` pour le signal d'interruption, `SIGTERM` pour le signal de terminaison, `SIGKILL` pour arrêter immédiatement un processus, etc.

La fonction `kill()` renvoie `0` en cas de succès et `-1` en cas d'erreur. En cas d'erreur, tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.25.3. kill() - Exemple

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("[M]Erreur lors du fork.\n");
		return (1);
	}
	else if (pid == 0)
	{
		// Le fils attend en boucle, ils doit être kill par le parent
		printf("[C] Je suis le fils (pid = %d).\n", getpid());
		while (1)
		{
			printf("[C] Je taff.\n");
			sleep(1);
		}
	}
	else
	{
		printf("[M] Je suis le parent (pid = %d).\n", getpid());
		printf("[M] Je vais attendre 5 secondes et kill() le fils.\n");
		// Le parent attend 5 secondes et kill le fils
		sleep(5);
		printf("[M] je tue le fils\n");
		if (kill(pid, SIGKILL) == -1)
		{
			printf("[M] Erreur lors du kill.\n");
			return (2);
		}
		// On attend la fin de l'exécution du fils
		waitpid(pid, NULL, 0);
		printf("[M] Le processus fils c'est terminé.\n");
	}
	return (0);
}
```

```text
[M] Je suis le parent (pid = 12083).
[M] Je vais attendre 5 secondes et kill() le fils.
[C] Je suis le fils (pid = 12084).
[C] Je taff.
[C] Je taff.
[C] Je taff.
[C] Je taff.
[C] Je taff.
[M] je tue le fils
[M] Le processus fils c'est terminé.
```

## 1.26. exit()

Tu connais déjà `open()` !!

## 1.27. getcwd()

### 1.27.1. getcwd() - Prototype

```c
#include <unistd.h>

char *getcwd(char *buf, size_t size);
```

### 1.27.2. getcwd() - Explications

La fonction `getcwd()` prend deux arguments :

- `buf` : Un pointeur vers un tampon (buffer) de caractères ou la chaine du chemin du réperoitre de travail sera stockée. Il est recommandl de fournir im tampon assez grand pour contenir le chemin complet, généralement défini comme un tableau de caractères.
- `size` : La taille du tampon (`buf`) en octets.

La fonction `getcwd()` renvoie un pointeur vers le tampon (`buf`) contenant le chemin complet du répertoire de travail. Si la fonction réussit, le tampon contiendra le chemin complet. Si le tampon est trop petit pour contenir le chemin complet, la fonction renverra `NULL`, et tu devras redimensionner le tampon avec un taille suffisante pour réussir l'appel suivant.

### 1.27.3. getcwd() - Exemple

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	// Création d'un buffer de 256 char
	char buf[256];

	// Récuperation du répértoire actuelle
	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		// Erreur lors de la récuperation du répertoir (souvent, buf trop petit)
		printf("Erreur lors de la récuperation du répertoire actuel\n");
		return (1);
	}
	// On affiche le répértoire actuel (buf)
	printf("Répertoire actuel : %s\n", buf);
	return (0);
}
```

```text
Répertoire actuel : /home/luca/Git/minishell
```

## 1.28. chdir()

### 1.28.1. chdir() - Prototype

```c
#include <unistd.h>

int chdir(const char *path);
```

### 1.28.2. chdir() - Explications

La fonction `chdir()` prend un argument :

- `path` : Un pointeur vers une chaine de caractères représentant le chemin du nouveau répertoire vers lequel tu souhaites changer. Cette chaine de caractères doit contenir le chemin absolu ou relatif du répertoire.

La fonction `chdir()` renvoie `0` en cas de succès et `-1` en cas d'erreur. En cas d'erreur, tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.28.3. chdir() - Exemple

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	// Création d'une string contenant le nouveau répertoire
	const char *newDir = "/etc";
	char buf[256];

	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		printf("Erreur lors de la récuperation du répertoire actuel\n");
		return (1);
	}
	printf("Répertoire actuel : %s\n", buf);
	// Changement de répertoire
	if (chdir(newDir) == -1)
	{
		printf("Erreur lors du changement de répertoire\n");
		return (2);
	}
	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		printf("Erreur lors de la récuperation du répertoire actuel\n");
		return (3);
	}
	printf("Répertoire actuel : %s\n", buf);
	return (0);
}
```

```text
Répertoire actuel : /home/luca/Git/minishell
Répertoire actuel : /etc
```

## 1.29. stat()

### 1.29.1. stat() - Prototype

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *path, struct stat *buf);
```

### 1.29.2. stat() - Explications

La fonction `stat()` prend deux arguments :

- `path` : Un pointeur vers une chaine de caractères représentant le chemin du fichier ou du répertoire dont tu souhaites obtenir les informations.
- `buf` : Un pointeur vers une structure `struct stat` dans laquelle les informations sur le fichier ou le répertoire seront stockées.

La structure `struct stat` est définie dans l'en-tête `<sys/stat.h>` et ressemble généralement à ceci :

```c
struct stat
{
	dev_t		st_dev;		// Identifiant du périphérique contenant le fichier
	ino_t		st_ino;		// Numéro d'inode
	mode_t		st_mode;	// Mode d'accès au fichier (permission)
	nlink_t		st_nlink;	// Nombre de liens matériels
	uid_t		st_uid;		// Identifiant de l'utilisateur propriétaire
	gid_t		st_gid;		// Identifiant du groupe propriétaire
	off_t		st_size;	// Taille du fichier en octets
	time_t		st_atime;	// Heure d'accès du fichier
	time_t		st_mtime;	// Heure de dernière modification du fichier
	time_t		st_ctime;	// Heure du dernier changement d'état du fichier
	blksize_t	st_blksize;	// Taille de bloc optimale pour E/S de fichiers
	blkcnt_t	st_blocks;	// Nombre de blocs alloués pour le fichier
};
```

La fonction `stat()` renvoie `0` en cas de succès et `-1` en cas d'erreur. En cas de succès, la structure `struct stat` pointée par `buf` contiendra les informations sur le fichier ou le répertoire spécifié par `path`. Si la fonction échoue, tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.29.3. stat() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	const char *filename = "playground.c";
	struct stat file_infos;

	if (stat(filename, &file_infos) == -1)
	{
		printf("Erreur lors de la récuperation des infos du fichier.\n");
		return (1);
	}
	printf("Information du fichier : %s\n", filename);
	printf("Taille du fichier : %ld octets\n", file_infos.st_size);
	printf("Permission (octal) : %o\n", file_infos.st_mode & 0777);
	printf("Propriétaire : UID=%u, GID=%u\n", file_infos.st_uid, file_infos.st_gid);
	return (0);
}
```

```text
Information du fichier : playground.c
Taille du fichier : 573 octets
Permission (octal) : 644
Propriétaire : UID=1000, GID=1000
```

## 1.30. lstat()

### 1.30.1. lstat() - Prototype

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int lstat(const char *path, struct stat *buf);
```

### 1.30.2. lstat() - Explications

La fonction `lstat()` prend deux arguments :

- `path` : Un pointeur vers une chaine de caractères représentant le chemin du fichier ou du répertoire (ou lien symbolique) dont tu souhaites obtenir les informations.
- `buf` : Un pointeur vers une structure `struct stat` dans la quelle les informations sur le fichier ou le lien symbolique seront stockées.

La structure `struct stat` est la même que celle utilisée avec la fonction stat() et est définie dans l'en-tête `<sys/stat.h>`.

La fonction `lstat()` renvoie `0` en cas de succès et `-1` en cas d'erreur. En cas de succès, la structure `struct stat` pointée par `buf` contiendra les informations sur le fichier ou le lien symbolique spécifié par `parh`. Si la fonction échoue, tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.30.3. lstat() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	const char *filenameSyn = "exemple.txt";
	struct stat syn_infos;
	const char *filenameReg = "playground.c";
	struct stat reg_infos;

	if (lstat(filenameReg, &reg_infos) == -1 || lstat(filenameSyn, &syn_infos) == -1)
	{
		printf("Erreur lors de la récuperation des infos du fichier.\n");
		return (1);
	}
	printf("Information du fichier ou le lien symbolique : %s\n", filenameSyn);
	printf("Type de fichier : ");
	if (S_ISREG(syn_infos.st_mode))
		printf("Fichier régulier\n");
	else if (S_ISDIR(syn_infos.st_mode))
		printf("Répertoire\n");
	else if (S_ISLNK(syn_infos.st_mode))
		printf("Lien symbolique\n");
	else
		printf("Type de fichier inconnu\n");
	printf("Information du fichier ou le lien symbolique : %s\n", filenameReg);
	printf("Type de fichier : ");
	if (S_ISREG(reg_infos.st_mode))
		printf("Fichier régulier\n");
	else if (S_ISDIR(reg_infos.st_mode))
		printf("Répertoire\n");
	else if (S_ISLNK(reg_infos.st_mode))
		printf("Lien symbolique\n");
	else
		printf("Type de fichier inconnu\n");
	return (0);
}
```

```text
Information du fichier ou le lien symbolique : exemple.txt
Type de fichier : Lien symbolique
Information du fichier ou le lien symbolique : playground.c
Type de fichier : Fichier régulier
```

## 1.31. fstat()

### 1.31.1. fstat() - Prototype

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int fstat(int fd, struct stat *buf);
```

### 1.31.2. fstat() - Explications

La fonction `fstat()` prend deux arguments :

- `fd` : Le descripteur de fichier pour lequel tu souhaites obtenir les informations. Un descripteur de fichier est généralementobtenu lors de l'ouverture d'un fichier avec les fonction comme `open()` ou `creat()`, ou lors de la redirection des entrées/sorties standard avec `stdin`, `stdout` et `stderr`.
- `buf` : Un pointeur vers une structure `struct stat` dans laquelle les informations sur le fichier associé au descripteur seront stockées.

La structure `struct stat` est la même que celle utilisée avec les fonction `stat()` et `lstat()`, eet elle est définie dans l'en-tête `<sys/stat.h>`.

La fonction `fstat()` renvoie `0` en cas de succès et `-1` en cas d'erreur. En cas de succès, la structure `struct stat` pointée par `buf` contiendra les informations sur le fichier associé au descipteur de fichier. Si la fonction écouhe, tu peux consulter la variables globale `errno` pour connaitre la nature de l'erreur.

### 1.31.3. fstat() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	const char *filename = "playground.c";
	int fd = open(filename, O_RDONLY);
	struct stat file_info;

	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return (1);
	}

	if (fstat(fd, &file_info) == -1)
	{
		printf("Erreur lors de la récuperation des infos du fichier.\n");
		return (2);
	}
	close(fd);
	printf("Information sur le fichier : %s.\n", filename);
	printf("Taille du fichier : %ld octets.\n", file_info.st_size);
	printf("Permission (octal) : %o.\n", file_info.st_mode & 0777);
	return (0);
}
```

```text
Information sur le fichier : playground.c.
Taille du fichier : 645 octets.
Permission (octal) : 644.
```

## 1.32. unlink()

### 1.32.1. unlink() - Prototype

```c
#include <unistd.h>

int unlink(const char *pathname);
```

### 1.32.2. unlink() - Explications

La fonction `unlink()` prend un argument :

- `pathname` : Un pointeur vers une chaine de caractères représentant le chemin du fichier que tu souhaite supprimer.

La fonction `unlink()` renvoie `0` en cas de succès et `-1` en cas d'erreur. En cas d'erreur, tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.32.3. unlink() - Exemple

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	const char *filename = "exemple.txt";

	// Suppression du fichier
	if (unlink(filename) == -1)
	{
		printf("Erreur lors de la suppression du fichier.\n");
		return (1);
	}
	printf("Le fichier \"%s\" a été supprimé avec succès.\n", filename);
	return (0);
}
```

```text
Le fichier "exemple.txt" a été supprimé avec succès.
```

```text
Erreur lors de la suppression du fichier.
```

Ici, j'ai lancé le programme deux fois. Lors du premier run, le fichier est bien supprimer et lors du deuxième, nous avons une erreur car le fichier n'existe plus.

## 1.33. execve()

### 1.33.1. execve() - Prototype

```c
#include <unistd>

int execve(const char *pathname, const char *argv[], const char *envp[]);
```

### 1.33.2. execve() - Explications

La fonction `execve()` prend trois arguments :

- `pathname` : Un pointeur vers une chaine de caractères représentant le chemin du programme exécutable que tu souhaites lancer. Le chemin doit inclure le nom du fichier exécutable.
- `argv` : Un tableau de pointeur de chaine de caractères qui représente les arguments passés au nouveau programme. Le premier élément `argv[0]` doit généralement contenir le nom du programme lui-même.
- `envp` : Un tableau de pointeur de chaine de caractères qui repésente les variable d'environnement spécifient l'environnement dans le quel le programme est exécuté.

La fonction `execve()` remplace le processus appelant par le nouveau programme spécifié. Si l'appel réussit, le nouveau programme prendra le contrôle et continuera son exécution. Si l'appel écouhe, `execve()` renverra `-1`m et tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.33.3. execve() - Exemple

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	char *const argv[] = { "ls", "-l", "/home/luca", NULL };
	char *const envp[] = { NULL };

	// Remplacer le programme actuel par "ls -l"
	if (execve("/bin/ls", argv, envp) == -1)
	{
		printf("Erreur lors du lancement du nouveau programme.\n");
		return (1);
	}
	// Cette oartie du code ne sera jamais exécutée
	return (0);
}
```

```text
total 12
drwxr-xr-x 3 luca luca 4096 Jul 26 15:26 Dev
drwxr-xr-x 6 luca luca 4096 Jul 26 17:53 Git
drwxr-xr-x 3 luca luca 4096 Jun 22 13:41 Projets
-rw-r--r-- 1 luca luca    0 Jul 28 19:49 exemple.txt
```

## 1.34. dup()

### 1.34.1. dup() - Prototype

```c
#include <unistd.h>

int dup(int oldfd);
```

### 1.34.2. dup() - Explications

La fonction `dup()` prend un argument :

- `oldfd` : Le descripteur de fichier que tu souhaites dupliquer.

La fonction `dup()` renvoie un nouveau descripteur de fichier, qui est le plus petit descripteur disponible parmi les descripteurs non utilisés dans le processus. Si l'appel échoue, la fonction renverra `-1`, et tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.34.3. dup() - Exemple

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd = dup(STDIN_FILENO);
	char buf[256];
	ssize_t sizeResult;

	if (fd == -1)
	{
		printf("Erreur lors de la duplication.\n");
		return (1);
	}
	printf("Descripteur original : %d\n", STDIN_FILENO);
	printf("Nouveau descripteur : %d\n", fd);

	sizeResult = read(STDIN_FILENO, buf, sizeof(buf));
	if (sizeResult == -1)
	{
		printf("Erreur lors de la lecture du descripteur de fichier.\n");
		return (2);
	}
	printf("Contenu lu avec le descripteur de fichier : %s\n", buf);
	sizeResult = read(fd, buf, sizeof(buf));
	if (sizeResult == -1)
	{
		printf("Erreur lors de la lecture du descripteur de fichier.\n");
		return (3);
	}
	printf("Contenu lu avec le nouveau descripteur de fichier : %s\n", buf);
	return (0);
}
```

```text
Descripteur original : 0
Nouveau descripteur : 3
aaaaaaaaa
Contenu lu avec le descripteur de fichier : aaaaaaaaa

bbbbbbbbbbbbbbbbb
Contenu lu avec le nouveau descripteur de fichier : bbbbbbbbbbbbbbbbb
```

## 1.35. dup2()

### 1.35.1. dup2() - Prototype

```c
#include <unistd.h>

int dup2(int oldfd, int newfd);
```

### 1.35.2. dup2() - Explications

La fonction `dup2()` prend deux arguments :

- `oldfd` : Le descipteur de fichier que tu souhaite dupliquer.
- `newfd` : Le numéro du descripteur de fichier que tu souhaites utiliser pour le nouveau descripteur. Si `newfd` est déjà ouvert, la fonction `dup2()` le fermera automatiquement avant de faire la duplication.

La fonction `dup2()` renvoie un nouveau descripteur de fichier, qui est équivalent à `newfd` et fait référence au même fichier ou au même flux de données que `oldfd`. Si l'appel échoue, la fonction renverra `-1`, et tu peux consulter la variable globale `errno` pour connaitre la nature de l 'erreur.

### 1.35.3. dup2() - Exemple

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	const char *filename = "sortie.txt";
	int filefd, saved_stdout;

	// Sauvegarder STDOUT
	saved_stdout = dup(STDOUT_FILENO);
	// Ouvrire le fichier
	filefd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filefd == -1)
		return (1);
	// Rediriger la sortie standard dans le fichier
	if (dup2(filefd, STDOUT_FILENO) == -1)
	{
		printf("Erreur lors de la duplication du descripteur.\n");
		close(filefd);
		return (2);
	}
	close(filefd);
	// Ecrire sur la sortie standard revient à écrire dans le fichier
	if (write(STDOUT_FILENO, "salut le fichier\n", strlen("salut le fichier\n")) == -1)
		return (3);
	// Redirigier la sortie standard sur sa valeur initial
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		return (4);
	// Ecrire sur la sortie standard revient à la normal
	if (write(STDOUT_FILENO, "salut le terminal\n", strlen("salut le terminal\n")) == -1)
		return (5);
	return 0;
}
```

```text
salut le terminal
```

```text
salut le fichier
```

## 1.36. pipe()

### 1.36.1. pipe() - Prototype

```c
#include <unistd.h>

int pipe(int pipefd[2]);
```

### 1.36.2. pipe() - Explications

La fonction `pipe()` prend un argument :

- `pipefd` : Un tableau d'entiers de taille 2 qui sera utilisé pour renvoyer les descripteurs de fichiers du tube. `pipefd[0]` sera le descripteur de lecture, et `pipefd[1]` sera le descripteur d'écriture.

La fonction `pipe()` renvoie `0` en cas de succès et `-1` en cas d'erreur, et tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

Après l'appel à `pipe()`, tu obtiendras un tube avec une extrémité de lecture (`pipefd[0]`) et une extrémité d'écriture (`pipefd[1]`). Les données écrites dans `pipefd[1]` par un processus peuvent être lues à partir de `pipefd[0]` par un autre processus. Le tube a une capacité limitée, et écrire dans le tube peut être bloquante si le tube est plein. De même, la lecture à partir du tubepeut être bloquante si le tube est vide.

### 1.36.3. pipe() - Exemple

```c
#include <stdio.h>
#include <unistd.h>

int main() {
	int pipefd[2];
	pid_t pid;
	char msg[] = "Hello team !!";
	char buf[100];

	// Creation du tuyau
	if (pipe(pipefd) == -1)
	{
		printf("Erreur lors de la création du tube.\n");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		printf("Erreur lors du fork.\n");
		return (2);
	}
	if (pid == 0)
	{
		// Nous fermont pipefd[1] car nous n'avons pas besoin pour la lecture
		close(pipefd[1]);
		// Le fils lit dans le tuyau pour afficher le message
		if (read(pipefd[0], buf, sizeof(buf)) == -1)
		{
			printf("Erreur lors de la lecture du tuyau.\n");
			return (3);
		}
		// Nous fermons pipefd[0] car nous n'en n'avons plus besoin
		close(pipefd[0]);
		printf("[C] Nouveau message : %s\n", buf);
	}
	else
	{
		// Nous fermons pipefd[0] car nous n'en n'avons pas besoin pour l'écriture
		close(pipefd[0]);
		printf("[P] Ecriture du message dans le tuyau.\n");
		// Le parent envoie le message dans le tuyau
		if (write(pipefd[1], msg, sizeof(msg)) == -1)
		{
			printf("Erreur lors de l'écriture dans le tuyau.\n");
			return (4);
		}
		// Nous fermons pipefd[1] car nous n'en n'avons plus besoin
		close(pipefd[1]);
	}
	return 0;
}
```

```text
[P] Ecriture du message dans le tuyau.
[C] Nouveau message : Hello team !!
```

## 1.37. opendir()

### 1.37.1. opendir() - Prototype

```c
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *dirname);
```

### 1.37.2. opendir() - Explications

La fonction `opendir()` prend un argument :

- `dirname` : le nom du répertoire que tu souhaites ouvrir. Il doit être passé en tant que chaine de caracrtères.

La fonction `opendir()` renvoie un pointeur de type `DIR *` qui représente le descripteur du répertoire, en cas de succès. Si l'appel échoue, elle renverra `NULL`, et tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.37.3. opendir() - Exemple

```c
#include <stdio.h>
#include <dirent.h>

int main() {
	const char *dirname = "/home/luca";
	DIR *dir;

	// Ouverture du répertoire
	dir = opendir(dirname);
	if (dir == NULL)
	{
		printf("Impossible d'ouvrir le répertoire.\n");
		return (1);
	}
	// Fermeture du répertoire
	closedir(dir);
	return (0);
}
```

```text

```

## 1.38. readdir()

### 1.38.1. readdir() - Prototype

```c
#include <dirent.h>

struct dirent *readdir(DIR *dirp);
```

### 1.38.2. readdir() - Explications

La fonction `readdir()` prend un argument :

- `dirp` : Un pointeur de type `DIR *` qui représente le descripteur du répertoire, obtenu à l'aide de la fonction `opendir()`.

La fonction `readdir()` renvoie un pointeur de type `struct dirent *` qui représente la prochaine entrée du répertoire, sous forme de structure `struct dirent`. Si la fin du répertoire est atteinte ou en cas d'erreur, elle renverra `NULL`.

```c
struct dirent
{
	ino_t			d_ino;		// Numéro d'inode
	off_t			d_off;		// Décalage à la prochaine entrée
	unsigned short	d_reclen;	// Longeur de cet enregistrement
	unsigned char	d_type;		// Type d'entrée (par exemple, DT_REG, DT_DIR, etc.)
	char			d_name[];	// Nom de l'entrée
}
```

La valeur `d_name` est le nom de l'entrée (fichier ou sous répertoire) dans le répertoire.

### 1.38.3. readdir() - Exemple

```c
#include <stdio.h>
#include <dirent.h>

int main() {
	const char *dirname = ".";
	DIR *dir;
	struct dirent *entry;

	// Ouverture du répertoire
	dir = opendir(dirname);
	if (dir == NULL)
	{
		printf("Impossible d'ouvrir le répertoire.\n");
		return (1);
	}
	// Parcourir le répertoire
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_REG)
			printf("Fichier\t\t: %s\n", entry->d_name);
		else if (entry->d_type == DT_DIR)
			printf("Répertoire\t: %s\n", entry->d_name);
		else if (entry->d_type == DT_LNK)
			printf("Lien symbolique\t: %s\n", entry->d_name);
		else
			printf("Type inconnu\t: %s\n", entry->d_name);
	}
	// Fermeture du répertoire
	closedir(dir);
	return (0);
}
```

```text
Fichier         : README.md
Fichier         : playground.o
Répertoire      : .
Répertoire      : ..
Fichier         : Makefile
Fichier         : sortie.txt
Lien symbolique : exemple.txt
Répertoire      : docs
Fichier         : tests
Répertoire      : .vscode
Fichier         : playground.c
Répertoire      : .git
Fichier         : .gitignore
```

## 1.39. closedir()

### 1.39.1. closedir() - Prototype

```c
#include <dirent.h>

int closedir(DIR *dirp);
```

### 1.39.2. closedir() - Explications

La fonction `closedir()` prend un argument :

- `dirp` : Un pointeur de type `DIR *` qui représente le descripteur du répertoire que tu souhaites fermer. Ce descripteur a été obtenu à l'aide de la fonction `opendir()` lors de l'ouverture du répertoire.

La fonction `closedir()` ne renvoie pas de valeur de retour significative. Elle retourne `0` en cas de succès et `-1` en cas d'échec. Si tu souhaites gérer les erreurs, tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

## 1.40. strerror()

### 1.40.1. strerror() - Prototype

```c
#include <string.h>

char *strerror(int errnum);
```

### 1.40.2. strerror() - Explications

La fonction `strerror()` prend un argument :

- `errnum` : Le code d'erreur pour lequel tu veux obtenir la description. Ce code d'erreur est généralement stocké dans la variable globale `errno` après l'appel à une fonction qui a échoué.

la fonction `strerror()` renvoie un pointeur vers une chaine de caractères statique contenant la description de l'erreur associée au code `errnum`.

### 1.40.3. strerror() - Exemple

```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	// Code d'erreur pour la permission refusée
	int errcode = EACCES;
	// Obtenir la description de l'erreur associée au code d'erreur
	const char *errmsg = strerror(errcode);

	printf("Erreur : %s\n", errmsg);
	return (0);
}
```

```text
Erreur : Permission denied
```

## 1.41. perror()

### 1.41.1. perror() - Prototype

```c
#include <stdio.h>

void perror(const char *s);
```

### 1.41.2. perror() - Explications

La fonction `perror()` prend un argument optionnel :

- `s` : Un pointeur vers une chaine de caractères qui sera affichée avant la description de l'erreur. Cet argument est facultatif, et tu peux le laisser `NULL` si tu ne souhaites pas afficher de message supplémentaire.

La fonction `perror()` n'a pas de valeur de retour.

### 1.41.3. perror() - Exemple

```c
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main() {
	int fd;

	fd = open("fichier_qui_n_exite_pas.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	return (0);
}
```

```text
Erreur lors de l'ouverture du fichier: No such file or directory
```

## 1.42. isatty()

### 1.42.1. isatty() - Prototype

```c
#include <unistd.h>

int isatty(int fd);
```

### 1.42.2. isatty() - Explications

La fonction `isatty()` prend un argument :

- `fd` : le descripteur de fichier que tu veux vérifié si'il est associé à un terminal. Un descripteur de fichier est un entier qui représente un fichier ouvert, un fichier standard (par exemple, stdin, stdout, stderr) ou une connexion réseau.

La fonction `isatty` renvoie `1` si le descripteur de fichier `fd` est associé à un terminal interactif, `0` sinon.

### 1.42.3. isatty() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;

	fd = open("exemple.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	if (isatty(STDIN_FILENO))
		printf("Le fd est un terminal interactif.\n");
	else
		printf("Le fd n'est pas un terminal interactif.\n");
	if (isatty(fd))
		printf("Le fd est un terminal interactif.\n");
	else
		printf("Le fd n'est pas un terminal interactif.\n");
	return (0);
}
```

```text
Le fd est un terminal interactif.
Le fd n'est pas un terminal interactif.
```

## 1.43. ttyname()

### 1.43.1. ttyname() - Prototype

```c
#include <unistd.h>

char *ttyname(int fd);
```

### 1.43.2. ttyname() - Explications

La fonction `ttyname()` prend un argument :

- `fd` : Le descripteur de fichier pour lequel tu souhaites obtenir le nom du terminal.

La fonction `ttyname()` renvoie un pointeur vers une chaine de caractères contenant le nom du terminal si `fd` est associé à un terminal. Si `fd` n'est pas associé à un terminal, elle renvoie `NULL`.

### 1.43.3. ttyname() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char *termName = ttyname(STDIN_FILENO);

	if (termName != NULL)
		printf("L'entrée standard est associée au terminal : %s\n", termName);
	else
		printf("Le fd n'est pas associé à un terminal.\n");
	return (0);
}
```

```text
L'entrée standard est associée au terminal : /dev/pts/0
```

## 1.44. ttyslot()

### 1.44.1. ttyslot() - Prototype

```c
#include <unistd.h>

int ttyslot(void);
```

### 1.44.2. ttyslot() - Explications

La fonction `ttyslot()` ne prend aucun argument.

La dfnction `ttyslot()` renvoie un entier qui représente le numéro de l'entrée dans la table des terminaux associée au terminal interactif courant. Si aucun terminal n'est interactif n'est associcié, ou s'il y a une erreur, la fonction renverra la valeur `-1`.

### 1.44.3. ttyslot() - Exemple

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	int slot = ttyslot();

	if (slot != -1)
		printf("Le numéro de l'entrée dans la table des terminaux est : %d.\n", slot);
	else
		printf("Aucun terminal interactif n'est associé ou une erreur c'est produite.\n");
	return (0);
}
```

```text
Le numéro de l'entrée dans la table des terminaux est : 0.
```

### 1.44.4. ttyslot() - Notes

La fonction `ttyslot()` est généralement disponible dabns es anciennes bibliothèque système UNIX et est utilisée pour déterminer le numéro de l'entrée du terminal associée au processus. Le numéro de l'entrée de terminal est utilis pour récupérer les informations sur le terminal à partir du fichier `/etc/ttys`.

Cependant, cette fonction n'est pas standard et n'est pas portable sur toutes les plates-formes. De plus, les système moderne utilisent souvent d'autres mécanismes pour la gestion des terminaux et tty. Pour cette raison, l'utilisation de `ttyslot()` est déconseillée dabns les nouveaux programmes et il est préférable d'utiliser des méthodes plus modernes et portable pour la gestion des terminaux.

Si tu a besoin d'informations sur le terminal, tu devrais plutôt utiliser les fonctions modernes telles qui `tcgetattr()` et `tcsetattr()` pour obtenir et configurer les paramètres du terminal. Ces fonctions sont définies dans l'en-tête `<termios.h>` et offrent une meilleure portabilité et de meilleures fonctionnalités pour la gestion des terminaux.

## 1.45. ioctl()

### 1.45.1. ioctl() - Prototype

```c
#include <sys/ioctl.h>

int ioctl(int fd, unsigned long request, ...);
```

### 1.45.2. ioctl() - Explications

La fonction `ioctl()` prend trois arguments principaux :

- `fd` : Le descripteur de fichier associé au périphérique ou à la ressource que tu souhaites contrôler. Ce descripteur doit être ouvert avec les droits appropriés pour que l'appel réussisse.
- `request` : Une valeur de type `unsigned long` qui représente la commande spécifique au périphérique ou à la ressource que tu souhaites exécuter. Cette valeur varie selon le périphérique ou la ressources, et est généralement définie dans des en-têttes pécifiques au périphérique ou au système.
- `...` : Des arguments optionnels supplémentaire dépendant de la commande spécifique (`request`). Certaines commandes peuvent nécessiter des argument supplémentaires, tandis que d'autres peuvent ne pas en nécessiter.

La fonction `ioctl()` renvoie une valeur entière, généralement `0` en cas de succès, et `-1` en cas d'échec. Si l'appel échoue, tu peux consulter la variable globale `errno` pour connaitre la nature de l'erreur.

### 1.45.3. ioctl() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

int main()
{
	int fd = open("exemple.txt", O_RDONLY);
	int flags; // Pour stocker les indicateur de fichier actuels
	int ret; // Pour stocker la valeur de retour de ioctl()
	int non_blocking = 1;

	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return (1);
	}
	// Activation du mode non-bloquant
	ret = ioctl(fd, FIONBIO, &non_blocking);
	if (ret == -1)
	{
		printf("Erreur lors de la définition du mode non-bloquant.\n");
		return(2);
	}
	// Vérifier si le mode non-bloquant est activé
	ret = ioctl(fd, FIONBIO, &flags);
	if (ret == -1)
	{
		printf("Erreur lors de la récupération du mode non-bloquant.\n");
		return (3);
	}
	close(fd);
	if (flags != -1)
		printf("Le mode non-bloquant est activé.\n");
	else
		printf("Le mode non-bloquant n'est pas activé.\n");
	return (0);
}
```

```text
Le mode non-bloquant est activé.
```

### 1.45.4. ioctl() - Notes

Cette fonction, c'est le bordel. Je n'ai pas bien compris ou l'utiliser dans le projet et pourquoi. Je ne sais pas non plus ou trouver les `request` qui sont propres à chaque périphérique ou ressources. Il va falloir creuser ...

## 1.46. getenv()

### 1.46.1. getenv() - Prototype

```c
#include <stdlib.h>

char *getenv(const char *name);
```

### 1.46.2. getenv() - Explications

la fonction `getenv()` prend un argument :

- `name` : C'est une chaine de caractères qui représente le nom de la variable d'environnement dont tu souhaites obtenir la valeur.

La fonction `getenv()` renvoie un pointeur vers une chaine de caractères contenant la valeur de la variable d'environnement spécifiée (`name`). Si la variable d'environnement n'est pas trouvée, la fonction renverra un pointeur NULL.

### 1.46.3. getenv() - Exemple

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Récupération de la variable d'environnement PATH
	char *env_paths = getenv("PATH");

	// Affichage de la variable d'environnement PATH
	if (env_paths != NULL)
		printf("PATH :\n%s\n", env_paths);
	else
		printf("La variable d'environnement PATH n'existe pas.\n");
	return (0);
}
```

```text
PATH :
/home/luca/.vscode-server/bin/2ccd690cbff1569e4a83d7c43d45101f817401dc/bin/remote-cli:/home/linuxbrew/.linuxbrew/bin:/home/linuxbrew/.linuxbrew/sbin:/home/luca/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files/Intel/WiFi/bin/:/mnt/c/Program Files/Common Files/Intel/WirelessCommon/:/mnt/c/Users/lucar/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/lucar/AppData/Local/Programs/oh-my-posh/bin:/mnt/c/Users/lucar/AppData/Local/Programs/Microsoft VS Code/bin:/snap/bin
```

## 1.47. tcsetattr()

### 1.47.1. tcsetattr() - Prototype

```c
#include <termios.h>

int tcsetattr(int fd, int optional_action, const struct termios *termios_p);
```

### 1.47.2. tcsetattr() - Explications

La fonction `tcsetattr()` prend trois arguments :

- `fd` : Le descripteur de fichier du terminal que tu souhaites configurer. Dans la plupart des cas, cela sera `0` pour l'entrée standard (`stdint`), `1` pour la sortie standard (`stdout`) ou `2` pour la sortie d'erreur (`stderr`). Cependant, il est également possible d'utiliser une descripteur de fichier ouvert pour un terminal spécifique.
- `optional_actions` : C'est un drapeau qui spécifie quand les changement doivent être appliqués. Il peut prendre l'une des valeur suivant :
  - `TCSANOW` : Appliquer les changement immédiatement.
  - `TCSADRAIN` : Attendre que tous les caractères en cours d'écriture soient transmis avant d'appliquer les changements.
  - `TCSAFLUSH` : Attendre que tous les caractères en cours d'écriture soient transmis, et vider les caractères en cours de lecture avant d'appliquer les changements.
- `termios_p` : Un pointeur vers une structure `struct termios` contenant les nouveaux attributs que tu souhaites configurer pour le terminal.

La structure `struct termios` contient de nombreux champs qui définissent les attributs du terminal. Par exemple, les champs `c_iflag`, `c_oflag`, `c_cflag`, `c_lflag` définissent les indicateurs de contrôle d'entrée, de sortie, les attributs du terminal, et les indicateurs de mode local, respectivement.

### 1.47.3. tcsetattr() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main()
{
	struct termios term_settings;

	// Récupération des paramètre actuel du terminal
	if (tcgetattr(STDIN_FILENO, &term_settings) == -1)
	{
		printf("Erreur lors de la récupèreation des paramètre du terminal.\n");
		return (1);
	}
	// Activer le mode cannonique dans les options
	term_settings.c_lflag |= ICANON;
	// Application des nouveaux paramètres
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term_settings) == -1)
	{
		printf("Erreur lors de l'appliquation des nouveaux paramètres.\n");
		return (2);
	}
	printf("Le mode canonique du terminal est activé.\n");
	printf("Appuyez sur 'Entrée' pour soumettre une ligne de texte.\n");
	// Attendre une entrée de l'utilisateur
	getchar();
	// Rétablire les paramètres par défaut du terminal
	term_settings.c_lflag &= -ICANON;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term_settings) == -1)
	{
		printf("Erreur lros du retablissement des paramètre par défaut du terminal.\n");
		return (3);
	}
	return (0);
}
```

```text
Le mode canonique du terminal est activé.
Appuyez sur 'Entrée' pour soumettre une ligne de texte.
Hello team !!
```

### 1.47.4. tcsetattr() - Notes

Je n'ai vu que une petite partie de se que peut faire cette fonction , il va falloir creuser...

## 1.48. tcgetattr()

### 1.48.1. tcgetattr() - Prototype

```c
#include <termios.h>

int tcgetattr(int fd, struct termios, *termios_p);
```

### 1.48.2. tcgetattr() - Explications

La fonction `tcgetattr()` prendre deux arguments :

- `fd` : Le descripteur de fichier du terminal dont tu souhaites récupérer les paramètre. Dans la plupart des cas, cela sera `0` pour l'entrée standard (`stdin`), `1` pour la sortie standard (`stdout`) ou `2` pour la sortie d'erreur (`stderr`). Cependant, il est également possible d'utiliser un descripteur de fichier ouvert pour un terminal spécifique.
- `termios_p` : Un pointeur ver une strucure `struct termios` ou les paramètres du terminal seront stockés.

La structure `struct termios` contient de nombreux champs qui définissent les attributs du terminal. Par exemple, les champs `c_iflag`, `c_oflag`, `c_cflag` et `c_lflag` définissenmt les indicateurs de contrôle d'entrée, de sortie, les attributs du terminal, et les indicateur de mode local, respectivement.

### 1.48.3. tcgetattr() - Exemple

```c
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main()
{
	struct termios term_settings;

	// Récupération des paramètre du terminal
	if (tcgetattr(STDIN_FILENO, &term_settings) == -1)
	{
		printf("Erreur lors de la récupération des paramètres du terminal.\n");
		return (1);
	}
	// Affichage des paramètres
	printf("Paramètres actuels du terminal :\n");
	printf("c_iflag: %#x\n", term_settings.c_iflag);
	printf("c_oflag: %#x\n", term_settings.c_oflag);
	printf("c_cflag: %#x\n", term_settings.c_cflag);
	printf("c_lflag: %#x\n", term_settings.c_lflag);
	printf("c_ispeed: %#x\n", term_settings.c_ispeed);
	printf("c_ospeed: %#x\n", term_settings.c_ospeed);
	return (0);
}
```

```text
Paramètres actuels du terminal :
c_iflag: 0x6d02
c_oflag: 0x5
c_cflag: 0x4bf
c_lflag: 0x8a3a
c_ispeed: 0xf
c_ospeed: 0xf
```
## 1.49. tgetent()

### 1.49.1. tgetent() - Prototype

```c
#include <term.h>

int tgetent(char *bp, const char *name);
```

### 1.49.2. tgetent() - Explications

La fonction `tgetent()` est utilisée pour initialiser la bibliothèque `Curses` avec les informations du terminal spécifié par le nom `name`. Elle remplit le tempon `bp` avec les capacités du terminal, qui seront utilisée par les autres fonctions de la bibliothèque pour contrôler le terminal de manière appropriée.

### 1.49.3. tgetent() - Exemple

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main()
{
	char term_buffer[2048];
	char *term_name = getenv("TERM");

	if (tgetent(term_buffer, term_name) == -1)
	{
		printf("Erreur lors de l'initalisation de Curses.\n");
		return (1);
	}
	printf("Curses initalisée.\n");
	return (0);
}
```

```text
Curses initalisée.
```

### 1.49.4. tgetent() - Notes

Nous utilisons des fonctions de la bibliothèque `Curses`, afin que le linkage se passe bien, il faut compiler avec le flag `-lcurses`.

Ce n'est pas claire si il faut utiliser le header `<term.h>`, `<curses.h>`ou les deux certaine documentations les documentations se contredisent. Sur mon système (Ubuntu), je doit mettre `<term.h>` afin que la compilation se déroule bien. Il faudra voir sur les Mac de cluster.

il n'est pas claire non plus si il faut utiliser `<curses>` ou `<ncurses>`. Sur mon système les deux fonctionne (`-lcurses` et `-lncurses` lors de la compilation) avec `<term.h>`. Il faudra voir sur les Mac de cluster.

## 1.50. tgetflag()

### 1.50.1. tgetflag() - Prototype

```c
#include <term.h>

int tgetflag(char *id);
```

### 1.50.2. tgetflag() - Explications

La fonction `tgetflag()` est utilisée pour récupérer la valeur d'un indicateur de terminal spécifié par son identifiant (`id`). Les indicateurs de terminal sont des caractéristiques spécifiques du terminal qui sont stockées dans les informations du terminal chargées par la fonction `tgetent()`.

### 1.50.3. tgetflag() - Exemple

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main()
{
	char term_buffer[2048];
	char *term_name = getenv("TERM");

	if (tgetent(term_buffer, term_name) == -1)
	{
		printf("Erreur lors de l'initalisation de Curses.\n");
		return (1);
	}
	printf("Indicateur de terminal pour %s.\n", term_name);
	printf("Auto wraparound (am): %d\n", tgetflag("am"));
	printf("Edition de texte (eo): %d\n", tgetflag("eo"));
	return (0);
}
```

```text
Indicateur de terminal pour xterm-256color.
Auto wraparound (am): 1
Edition de texte (eo): 0
```

## 1.51. tgetnum()

### 1.51.1. tgetnum() - Prototype

```c
#include <term.h>

int tgetnum(char *id);
```

### 1.51.2. tgetnum() - Explication

La fonction `tgetnum()` est utilisée pour récupérer la valeur numérique associée à la capacité du terminal spécifiée par son identifiant (`id`). Les capacités di terminal sont des caractèristiques spécifique du terminal qui sont stockées dans les informations du terminal chargées par la fonction `tgetent()`.

### 1.51.3. tgetnum() - Exemple

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main()
{
	char term_buffer[2048];
	char *term_name = getenv("TERM");
	int cols = 0;
	int rows = 0;

	if (tgetent(term_buffer, term_name) == -1)
	{
		printf("Erreur lors de l'initalisation de Curses.\n");
		return (1);
	}
	// Récupération du nombre de lignes et de colonnes
	cols = tgetnum("cols");
	rows = tgetnum("lines");
	printf("Le terminal comporte %d colonnes et %d lignes.\n", cols, rows);
	return (0);
}
```

```text
Le terminal comporte 60 colonnes et 55 lignes.
```

```text
Le terminal comporte 125 colonnes et 58 lignes.
```

Ici, j'ai lancé le programme deux fois en redimensionnant mon terminal entre les deux run . Ceci permet de constater que les valeur varie comme il le faut.

## 1.52. tgetstr()

### 1.52.1. tgetstr() - Prototype

```c
#include <term.h>

char *tgetstr(char *id, char **area);
```

### 1.52.2. tgetstr() - Explications

La fonction `tgetstr()` est utilisée pour récupérer la séquence d'échappement (chaine de caractères) associée à la capacité du terminal spécifiée par sont identifiant (`id`). Les capacités du terminal sont des caractéristiques spécifiques du terminal qui sont stockées dans les infoimation du terminal chargées par la fonction `tgetent()`.

La séquence d'échappement retournée par `tgetent()` est généralement une chaine de caractères qui permet de contrôler le terminal pour effectuer des opérations avancées, telle que le déplacement du curseur, l'effacement de l'écran, etc.

### 1.52.3. tgetstr() - Exemple

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main()
{
	char term_buffer[2048];
	char *term_name = getenv("TERM");
	char *result;

	if (tgetent(term_buffer, term_name) == -1)
	{
		printf("Erreur lors de l'initalisation de Curses.\n");
		return (1);
	}
	result = tgetstr("clear", NULL);
	if (result != NULL)
	{
		printf("%s\n", result);
		printf("L'écran a été clear.\n");
	}
	else
		printf("La capacité pour effacer l'écran n'est pas disponible pour le terminal %s.\n", term_name);
	return (0);
}
```

```text
L'écran a été clear.
```

### 1.52.4. tgetstr() - Notes

Il existe plusieurs `id` que nous pouvons utiliser pour intéréagir avec le terminal. Ils dépendent du terminal qui est utiliser. Pour les récupérer,nous pouvons utiliser la commande `infocmp $TERM` afin de les connaitre toutes.

Je n'ai pas bien compris comment fonction `char **area`. Visiblement, nous pouvons lui passer un buffer, mais je ne sais pas pourquoi faire .Il va falloir creusé...

## 1.53. tgoto()

### 1.53.1. tgoto() - Prototype

```c
#include <term.h>

char *tgoto(const char *cap, int col, int row);
```

### 1.53.2. tgoto() - Explications

La fonction `tgoto()` est utilisée pour construire un séquence d'échappement complète pour déplacer le curseur du terminal à une position spécifique, en utilisant la capacité du terminal spécifiée par `cap`. Cette fonction prend également deux entier `col` et `row` qui représente les coordonnées de la colonne et de léaligne de destination du curseur.

### 1.53.3. tgoto() - Exemple

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main()
{
	char term_buffer[2048];
	char *term_name = getenv("TERM");
	char *move_cursor_seq;

	if (tgetent(term_buffer, term_name) == -1)
	{
		printf("Erreur lors de l'initalisation de Curses.\n");
		return (1);
	}
	move_cursor_seq = tgoto(tgetstr("cm", NULL), 10, 5);
	if (move_cursor_seq != NULL)
		printf("%s", move_cursor_seq);
	else
		printf("La capacité pour déplacer le curseur n'est pas disponible pour ce terminal.\n");
	return (0);
}
```

## 1.54. tputs()

### 1.54.1. tputs() - Prototype

```c
#include <term.h>

int tputs(const char *str, int affcnt, int(*putc)(int));
```

### 1.54.2. tputs() - Explications

La fonction `tputs()` envoie la séquence d'échappement spécifiée par la chaine `str` directement au terminal. Cette fonction utilise une fonction de rappel (`putfunc`) pour envoyer chaque caractère de la séquence. Le paramètre `affcnt` est utilisé pour spécifié le nombre de ligne à afficher après l'envoi de la séquence (il est généralement utilisé pour gérer le défilement du terminal).

### 1.54.3. tputs() - Exemple

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main()
{
	char term_buffer[2048];
	char *term_name = getenv("TERM");
	// La variable qui va stocker la séquence de charactère pour clear
	char *clear_screen_seq;

	if (tgetent(term_buffer, term_name) == -1)
	{
		printf("Erreur lors de l'initalisation de Curses.\n");
		return (1);
	}
	// Récupération de la séquence de clear
	clear_screen_seq = tgetstr("clear", NULL);
	if (clear_screen_seq != NULL)
	{
		// Utilisation de la séquence clear
		tputs(clear_screen_seq, 1, putchar);
		printf("\nLe terminal a été effacer.\n");
	}
	else
	{
		printf("Erreur, le terminal ne prend pas en charge la capacité pour effacer l'écran.\n");
		return (2);
	}
	return (0);
}
```

```text
Le terminal a été effacer.
```
