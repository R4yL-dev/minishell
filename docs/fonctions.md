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
		- [1.24.4. sigaddset() - Notes](#1244-sigaddset---notes)
	- [1.25. kill()](#125-kill)
		- [1.25.1. kill() - Prototype](#1251-kill---prototype)
		- [1.25.2. kill() - Explications](#1252-kill---explications)
		- [1.25.3. kill() - Exemple](#1253-kill---exemple)
		- [1.25.4. kill() - Notes](#1254-kill---notes)
	- [1.26. exit()](#126-exit)
		- [1.26.1. exit() - Prototype](#1261-exit---prototype)
		- [1.26.2. exit() - Explications](#1262-exit---explications)
		- [1.26.3. exit() - Exemple](#1263-exit---exemple)
		- [1.26.4. exit() - Notes](#1264-exit---notes)
	- [1.27. getcwd()](#127-getcwd)
		- [1.27.1. getcwd() - Prototype](#1271-getcwd---prototype)
		- [1.27.2. getcwd() - Explications](#1272-getcwd---explications)
		- [1.27.3. getcwd() - Exemple](#1273-getcwd---exemple)
		- [1.27.4. getcwd() - Notes](#1274-getcwd---notes)
	- [1.28. chdir()](#128-chdir)
		- [1.28.1. chdir() - Prototype](#1281-chdir---prototype)
		- [1.28.2. chdir() - Explications](#1282-chdir---explications)
		- [1.28.3. chdir() - Exemple](#1283-chdir---exemple)
		- [1.28.4. chdir() - Notes](#1284-chdir---notes)
	- [1.29. stat()](#129-stat)
		- [1.29.1. stat() - Prototype](#1291-stat---prototype)
		- [1.29.2. stat() - Explications](#1292-stat---explications)
		- [1.29.3. stat() - Exemple](#1293-stat---exemple)
		- [1.29.4. stat() - Notes](#1294-stat---notes)
	- [1.30. lstat()](#130-lstat)
		- [1.30.1. lstat() - Prototype](#1301-lstat---prototype)
		- [1.30.2. lstat() - Explications](#1302-lstat---explications)
		- [1.30.3. lstat() - Exemple](#1303-lstat---exemple)
		- [1.30.4. lstat() - Notes](#1304-lstat---notes)
	- [1.31. fstat()](#131-fstat)
		- [1.31.1. fstat() - Prototype](#1311-fstat---prototype)
		- [1.31.2. fstat() - Explications](#1312-fstat---explications)
		- [1.31.3. fstat() - Exemple](#1313-fstat---exemple)
		- [1.31.4. fstat() - Notes](#1314-fstat---notes)
	- [1.32. unlink()](#132-unlink)
		- [1.32.1. unlink() - Prototype](#1321-unlink---prototype)
		- [1.32.2. unlink() - Explications](#1322-unlink---explications)
		- [1.32.3. unlink() - Exemple](#1323-unlink---exemple)
		- [1.32.4. unlink() - Notes](#1324-unlink---notes)
	- [1.33. execve()](#133-execve)
		- [1.33.1. execve() - Prototype](#1331-execve---prototype)
		- [1.33.2. execve() - Explications](#1332-execve---explications)
		- [1.33.3. execve() - Exemple](#1333-execve---exemple)
		- [1.33.4. execve() - Notes](#1334-execve---notes)
	- [1.34. dup()](#134-dup)
		- [1.34.1. dup() - Prototype](#1341-dup---prototype)
		- [1.34.2. dup() - Explications](#1342-dup---explications)
		- [1.34.3. dup() - Exemple](#1343-dup---exemple)
		- [1.34.4. dup() - Notes](#1344-dup---notes)
	- [1.35. dup2()](#135-dup2)
		- [1.35.1. dup2() - Prototype](#1351-dup2---prototype)
		- [1.35.2. dup2() - Explications](#1352-dup2---explications)
		- [1.35.3. dup2() - Exemple](#1353-dup2---exemple)
		- [1.35.4. dup2() - Notes](#1354-dup2---notes)
	- [1.36. pipe()](#136-pipe)
		- [1.36.1. pipe() - Prototype](#1361-pipe---prototype)
		- [1.36.2. pipe() - Explications](#1362-pipe---explications)
		- [1.36.3. pipe() - Exemple](#1363-pipe---exemple)
		- [1.36.4. pipe() - Notes](#1364-pipe---notes)
	- [1.37. opendir()](#137-opendir)
		- [1.37.1. opendir() - Prototype](#1371-opendir---prototype)
		- [1.37.2. opendir() - Explications](#1372-opendir---explications)
		- [1.37.3. opendir() - Exemple](#1373-opendir---exemple)
		- [1.37.4. opendir() - Notes](#1374-opendir---notes)
	- [1.38. readdir()](#138-readdir)
		- [1.38.1. readdir() - Prototype](#1381-readdir---prototype)
		- [1.38.2. readdir() - Explications](#1382-readdir---explications)
		- [1.38.3. readdir() - Exemple](#1383-readdir---exemple)
		- [1.38.4. readdir() - Notes](#1384-readdir---notes)
	- [1.39. closedir()](#139-closedir)
		- [1.39.1. closedir() - Prototype](#1391-closedir---prototype)
		- [1.39.2. closedir() - Explications](#1392-closedir---explications)
		- [1.39.3. closedir() - Exemple](#1393-closedir---exemple)
		- [1.39.4. closedir() - Notes](#1394-closedir---notes)
	- [1.40. strerror()](#140-strerror)
		- [1.40.1. strerror() - Prototype](#1401-strerror---prototype)
		- [1.40.2. strerror() - Explications](#1402-strerror---explications)
		- [1.40.3. strerror() - Exemple](#1403-strerror---exemple)
		- [1.40.4. strerror() - Notes](#1404-strerror---notes)
	- [1.41. perror()](#141-perror)
		- [1.41.1. perror() - Prototype](#1411-perror---prototype)
		- [1.41.2. perror() - Explications](#1412-perror---explications)
		- [1.41.3. perror() - Exemple](#1413-perror---exemple)
		- [1.41.4. perror() - Notes](#1414-perror---notes)
	- [1.42. isatty()](#142-isatty)
		- [1.42.1. isatty() - Prototype](#1421-isatty---prototype)
		- [1.42.2. isatty() - Explications](#1422-isatty---explications)
		- [1.42.3. isatty() - Exemple](#1423-isatty---exemple)
		- [1.42.4. isatty() - Notes](#1424-isatty---notes)
	- [1.43. ttyname()](#143-ttyname)
		- [1.43.1. ttyname() - Prototype](#1431-ttyname---prototype)
		- [1.43.2. ttyname() - Explications](#1432-ttyname---explications)
		- [1.43.3. ttyname() - Exemple](#1433-ttyname---exemple)
		- [1.43.4. ttyname() - Notes](#1434-ttyname---notes)
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
		- [1.46.4. getenv() - Notes](#1464-getenv---notes)
	- [1.47. tcsetattr()](#147-tcsetattr)
		- [1.47.1. tcsetattr() - Prototype](#1471-tcsetattr---prototype)
		- [1.47.2. tcsetattr() - Explications](#1472-tcsetattr---explications)
		- [1.47.3. tcsetattr() - Exemple](#1473-tcsetattr---exemple)
		- [1.47.4. tcsetattr() - Notes](#1474-tcsetattr---notes)
	- [1.48. tcgetattr()](#148-tcgetattr)
		- [1.48.1. tcgetattr() - Prototype](#1481-tcgetattr---prototype)
		- [1.48.2. tcgetattr() - Explications](#1482-tcgetattr---explications)
		- [1.48.3. tcgetattr() - Exemple](#1483-tcgetattr---exemple)
		- [1.48.4. tcgetattr() - Notes](#1484-tcgetattr---notes)
	- [1.49. tgetent()](#149-tgetent)
		- [1.49.1. tgetent() - Prototype](#1491-tgetent---prototype)
		- [1.49.2. tgetent() - Explications](#1492-tgetent---explications)
		- [1.49.3. tgetent() - Exemple](#1493-tgetent---exemple)
		- [1.49.4. tgetent() - Notes](#1494-tgetent---notes)
	- [1.50. tgetflag()](#150-tgetflag)
		- [1.50.1. tgetflag() - Prototype](#1501-tgetflag---prototype)
		- [1.50.2. tgetflag() - Explications](#1502-tgetflag---explications)
		- [1.50.3. tgetflag() - Exemple](#1503-tgetflag---exemple)
		- [1.50.4. tgetflag() - Notes](#1504-tgetflag---notes)
	- [1.51. tgetnum()](#151-tgetnum)
		- [1.51.1. tgetnum() - Prototype](#1511-tgetnum---prototype)
		- [1.51.2. tgetnum() - Explications](#1512-tgetnum---explications)
		- [1.51.3. tgetnum() - Exemple](#1513-tgetnum---exemple)
		- [1.51.4. tgetnum() - Notes](#1514-tgetnum---notes)
	- [1.52. tgetstr()](#152-tgetstr)
		- [1.52.1. tgetstr() - Prototype](#1521-tgetstr---prototype)
		- [1.52.2. tgetstr() - Explications](#1522-tgetstr---explications)
		- [1.52.3. tgetstr() - Exemple](#1523-tgetstr---exemple)
		- [1.52.4. tgetstr() - Notes](#1524-tgetstr---notes)
	- [1.53. tgoto()](#153-tgoto)
		- [1.53.1. tgoto() - Prototype](#1531-tgoto---prototype)
		- [1.53.2. tgoto() - Explications](#1532-tgoto---explications)
		- [1.53.3. tgoto() - Exemple](#1533-tgoto---exemple)
		- [1.53.4. tgoto() - Notes](#1534-tgoto---notes)
	- [1.54. tputs()](#154-tputs)
		- [1.54.1. tputs() - Prototype](#1541-tputs---prototype)
		- [1.54.2. tputs() - Explications](#1542-tputs---explications)
		- [1.54.3. tputs() - Exemple](#1543-tputs---exemple)
		- [1.54.4. tputs() - Notes](#1544-tputs---notes)

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

Je n'ai pas encore tout bien compris, mais je crois que `wait3()` est un implémentation de `wait()` spécifique à certains systèmes UNIX. Peux être MOSX ?

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

### 1.23.2. sigemptyset() - Explications

### 1.23.3. sigemptyset() - Exemple

### 1.23.4. sigemptyset() - Notes

## 1.24. sigaddset()

### 1.24.1. sigaddset() - Prototype

### 1.24.2. sigaddset() - Explications

### 1.24.3. sigaddset() - Exemple

### 1.24.4. sigaddset() - Notes

## 1.25. kill()

### 1.25.1. kill() - Prototype

### 1.25.2. kill() - Explications

### 1.25.3. kill() - Exemple

### 1.25.4. kill() - Notes

## 1.26. exit()

### 1.26.1. exit() - Prototype

### 1.26.2. exit() - Explications

### 1.26.3. exit() - Exemple

### 1.26.4. exit() - Notes

## 1.27. getcwd()

### 1.27.1. getcwd() - Prototype

### 1.27.2. getcwd() - Explications

### 1.27.3. getcwd() - Exemple

### 1.27.4. getcwd() - Notes

## 1.28. chdir()

### 1.28.1. chdir() - Prototype

### 1.28.2. chdir() - Explications

### 1.28.3. chdir() - Exemple

### 1.28.4. chdir() - Notes

## 1.29. stat()

### 1.29.1. stat() - Prototype

### 1.29.2. stat() - Explications

### 1.29.3. stat() - Exemple

### 1.29.4. stat() - Notes

## 1.30. lstat()

### 1.30.1. lstat() - Prototype

### 1.30.2. lstat() - Explications

### 1.30.3. lstat() - Exemple

### 1.30.4. lstat() - Notes

## 1.31. fstat()

### 1.31.1. fstat() - Prototype

### 1.31.2. fstat() - Explications

### 1.31.3. fstat() - Exemple

### 1.31.4. fstat() - Notes

## 1.32. unlink()

### 1.32.1. unlink() - Prototype

### 1.32.2. unlink() - Explications

### 1.32.3. unlink() - Exemple

### 1.32.4. unlink() - Notes

## 1.33. execve()

### 1.33.1. execve() - Prototype

### 1.33.2. execve() - Explications

### 1.33.3. execve() - Exemple

### 1.33.4. execve() - Notes

## 1.34. dup()

### 1.34.1. dup() - Prototype

### 1.34.2. dup() - Explications

### 1.34.3. dup() - Exemple

### 1.34.4. dup() - Notes

## 1.35. dup2()

### 1.35.1. dup2() - Prototype

### 1.35.2. dup2() - Explications

### 1.35.3. dup2() - Exemple

### 1.35.4. dup2() - Notes

## 1.36. pipe()

### 1.36.1. pipe() - Prototype

### 1.36.2. pipe() - Explications

### 1.36.3. pipe() - Exemple

### 1.36.4. pipe() - Notes

## 1.37. opendir()

### 1.37.1. opendir() - Prototype

### 1.37.2. opendir() - Explications

### 1.37.3. opendir() - Exemple

### 1.37.4. opendir() - Notes

## 1.38. readdir()

### 1.38.1. readdir() - Prototype

### 1.38.2. readdir() - Explications

### 1.38.3. readdir() - Exemple

### 1.38.4. readdir() - Notes

## 1.39. closedir()

### 1.39.1. closedir() - Prototype

### 1.39.2. closedir() - Explications

### 1.39.3. closedir() - Exemple

### 1.39.4. closedir() - Notes

## 1.40. strerror()

### 1.40.1. strerror() - Prototype

### 1.40.2. strerror() - Explications

### 1.40.3. strerror() - Exemple

### 1.40.4. strerror() - Notes

## 1.41. perror()

### 1.41.1. perror() - Prototype

### 1.41.2. perror() - Explications

### 1.41.3. perror() - Exemple

### 1.41.4. perror() - Notes

## 1.42. isatty()

### 1.42.1. isatty() - Prototype

### 1.42.2. isatty() - Explications

### 1.42.3. isatty() - Exemple

### 1.42.4. isatty() - Notes

## 1.43. ttyname()

### 1.43.1. ttyname() - Prototype

### 1.43.2. ttyname() - Explications

### 1.43.3. ttyname() - Exemple

### 1.43.4. ttyname() - Notes

## 1.44. ttyslot()

### 1.44.1. ttyslot() - Prototype

### 1.44.2. ttyslot() - Explications

### 1.44.3. ttyslot() - Exemple

### 1.44.4. ttyslot() - Notes

## 1.45. ioctl()

### 1.45.1. ioctl() - Prototype

### 1.45.2. ioctl() - Explications

### 1.45.3. ioctl() - Exemple

### 1.45.4. ioctl() - Notes

## 1.46. getenv()

### 1.46.1. getenv() - Prototype

### 1.46.2. getenv() - Explications

### 1.46.3. getenv() - Exemple

### 1.46.4. getenv() - Notes

## 1.47. tcsetattr()

### 1.47.1. tcsetattr() - Prototype

### 1.47.2. tcsetattr() - Explications

### 1.47.3. tcsetattr() - Exemple

### 1.47.4. tcsetattr() - Notes

## 1.48. tcgetattr()

### 1.48.1. tcgetattr() - Prototype

### 1.48.2. tcgetattr() - Explications

### 1.48.3. tcgetattr() - Exemple

### 1.48.4. tcgetattr() - Notes

## 1.49. tgetent()

### 1.49.1. tgetent() - Prototype

### 1.49.2. tgetent() - Explications

### 1.49.3. tgetent() - Exemple

### 1.49.4. tgetent() - Notes

## 1.50. tgetflag()

### 1.50.1. tgetflag() - Prototype

### 1.50.2. tgetflag() - Explications

### 1.50.3. tgetflag() - Exemple

### 1.50.4. tgetflag() - Notes

## 1.51. tgetnum()

### 1.51.1. tgetnum() - Prototype

### 1.51.2. tgetnum() - Explications

### 1.51.3. tgetnum() - Exemple

### 1.51.4. tgetnum() - Notes

## 1.52. tgetstr()

### 1.52.1. tgetstr() - Prototype

### 1.52.2. tgetstr() - Explications

### 1.52.3. tgetstr() - Exemple

### 1.52.4. tgetstr() - Notes

## 1.53. tgoto()

### 1.53.1. tgoto() - Prototype

### 1.53.2. tgoto() - Explications

### 1.53.3. tgoto() - Exemple

### 1.53.4. tgoto() - Notes

## 1.54. tputs()

### 1.54.1. tputs() - Prototype

### 1.54.2. tputs() - Explications

### 1.54.3. tputs() - Exemple

### 1.54.4. tputs() - Notes
