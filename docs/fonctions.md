# 1. Fonctions autorisées

## 1.1. TOC

- [1. Fonctions autorisées](#1-fonctions-autorisées)
	- [1.1. TOC](#11-toc)
	- [1.2. readline()](#12-readline)
		- [1.2.1. readline() - Prototype](#121-readline---prototype)
		- [1.2.2. readline() - Expliquations](#122-readline---expliquations)
		- [1.2.3. readline() - Exemple](#123-readline---exemple)
		- [1.2.4. readline() - Notes](#124-readline---notes)
	- [1.3. rl\_clear\_history()](#13-rl_clear_history)
		- [1.3.1. rl\_clear\_history() - Prototype](#131-rl_clear_history---prototype)
		- [1.3.2. rl\_clear\_history() - Expliquations](#132-rl_clear_history---expliquations)
		- [1.3.3. rl\_clear\_history() - Exemple](#133-rl_clear_history---exemple)
		- [1.3.4. rl\_clear\_history() - Notes](#134-rl_clear_history---notes)
	- [1.4. rl\_on\_new\_line()](#14-rl_on_new_line)
		- [1.4.1. rl\_on\_new\_line() - Prototype](#141-rl_on_new_line---prototype)
		- [1.4.2. rl\_on\_new\_line() - Expliquations](#142-rl_on_new_line---expliquations)
		- [1.4.3. rl\_on\_new\_line() - Exemple](#143-rl_on_new_line---exemple)
		- [1.4.4. rl\_on\_new\_line() - Notes](#144-rl_on_new_line---notes)
	- [1.5. rl\_replace\_line()](#15-rl_replace_line)
		- [1.5.1. rl\_replace\_line() - Prototype](#151-rl_replace_line---prototype)
		- [1.5.2. rl\_replace\_line() - Expliquations](#152-rl_replace_line---expliquations)
		- [1.5.3. rl\_replace\_line() - Exemple](#153-rl_replace_line---exemple)
		- [1.5.4. rl\_replace\_line() - Notes](#154-rl_replace_line---notes)
	- [1.6. rl\_redisplay()](#16-rl_redisplay)
		- [1.6.1. rl\_redisplay() - Prototype](#161-rl_redisplay---prototype)
		- [1.6.2. rl\_redisplay() - Expliquations](#162-rl_redisplay---expliquations)
		- [1.6.3. rl\_redisplay() - Exemple](#163-rl_redisplay---exemple)
		- [1.6.4. rl\_redisplay() - Notes](#164-rl_redisplay---notes)
	- [1.7. add\_history()](#17-add_history)
		- [1.7.1. add\_history() - Prototype](#171-add_history---prototype)
		- [1.7.2. add\_history() - Expliquations](#172-add_history---expliquations)
		- [1.7.3. add\_history() - Exemple](#173-add_history---exemple)
		- [1.7.4. add\_history() - Notes](#174-add_history---notes)
	- [1.8. printf()](#18-printf)
		- [1.8.1. printf() - Prototype](#181-printf---prototype)
		- [1.8.2. printf() - Expliquations](#182-printf---expliquations)
		- [1.8.3. printf() - Exemple](#183-printf---exemple)
		- [1.8.4. printf() - Notes](#184-printf---notes)
	- [1.9. malloc()](#19-malloc)
		- [1.9.1. malloc() - Prototype](#191-malloc---prototype)
		- [1.9.2. malloc() - Expliquations](#192-malloc---expliquations)
		- [1.9.3. malloc() - Exemple](#193-malloc---exemple)
		- [1.9.4. malloc() - Notes](#194-malloc---notes)
	- [1.10. free()](#110-free)
		- [1.10.1. free() - Prototype](#1101-free---prototype)
		- [1.10.2. free() - Expliquations](#1102-free---expliquations)
		- [1.10.3. free() - Exemple](#1103-free---exemple)
		- [1.10.4. free() - Notes](#1104-free---notes)
	- [1.11. write()](#111-write)
		- [1.11.1. write() - Prototype](#1111-write---prototype)
		- [1.11.2. write() - Expliquations](#1112-write---expliquations)
		- [1.11.3. write() - Exemple](#1113-write---exemple)
		- [1.11.4. write() - Notes](#1114-write---notes)
	- [1.12. access()](#112-access)
		- [1.12.1. access() - Prototype](#1121-access---prototype)
		- [1.12.2. access() - Expliquations](#1122-access---expliquations)
		- [1.12.3. access() - Exemple](#1123-access---exemple)
		- [1.12.4. access() - Notes](#1124-access---notes)
	- [1.13. open()](#113-open)
		- [1.13.1. open() - Prototype](#1131-open---prototype)
		- [1.13.2. open() - Expliquations](#1132-open---expliquations)
		- [1.13.3. open() - Exemple](#1133-open---exemple)
		- [1.13.4. open() - Notes](#1134-open---notes)
	- [1.14. read()](#114-read)
		- [1.14.1. read() - Prototype](#1141-read---prototype)
		- [1.14.2. read() - Expliquations](#1142-read---expliquations)
		- [1.14.3. read() - Exemple](#1143-read---exemple)
		- [1.14.4. read() - Notes](#1144-read---notes)
	- [1.15. close()](#115-close)
		- [1.15.1. close() - Prototype](#1151-close---prototype)
		- [1.15.2. close() - Expliquations](#1152-close---expliquations)
		- [1.15.3. close() - Exemple](#1153-close---exemple)
		- [1.15.4. close() - Notes](#1154-close---notes)
	- [1.16. fork()](#116-fork)
		- [1.16.1. fork() - Prototype](#1161-fork---prototype)
		- [1.16.2. fork() - Expliquations](#1162-fork---expliquations)
		- [1.16.3. fork() - Exemple](#1163-fork---exemple)
		- [1.16.4. fork() - Notes](#1164-fork---notes)
	- [1.17. wait()](#117-wait)
		- [1.17.1. wait() - Prototype](#1171-wait---prototype)
		- [1.17.2. wait() - Expliquations](#1172-wait---expliquations)
		- [1.17.3. wait() - Exemple](#1173-wait---exemple)
		- [1.17.4. wait() - Notes](#1174-wait---notes)
	- [1.18. waitpid()](#118-waitpid)
		- [1.18.1. waitpid() - Prototype](#1181-waitpid---prototype)
		- [1.18.2. waitpid() - Expliquations](#1182-waitpid---expliquations)
		- [1.18.3. waitpid() - Exemple](#1183-waitpid---exemple)
		- [1.18.4. waitpid() - Notes](#1184-waitpid---notes)
	- [1.19. wait3()](#119-wait3)
		- [1.19.1. wait3() - Prototype](#1191-wait3---prototype)
		- [1.19.2. wait3() - Expliquations](#1192-wait3---expliquations)
		- [1.19.3. wait3() - Exemple](#1193-wait3---exemple)
		- [1.19.4. wait3() - Notes](#1194-wait3---notes)
	- [1.20. wait4()](#120-wait4)
		- [1.20.1. wait4() - Prototype](#1201-wait4---prototype)
		- [1.20.2. wait4() - Expliquations](#1202-wait4---expliquations)
		- [1.20.3. wait4() - Exemple](#1203-wait4---exemple)
		- [1.20.4. wait4() - Notes](#1204-wait4---notes)
	- [1.21. signal()](#121-signal)
		- [1.21.1. signal() - Prototype](#1211-signal---prototype)
		- [1.21.2. signal() - Expliquations](#1212-signal---expliquations)
		- [1.21.3. signal() - Exemple](#1213-signal---exemple)
		- [1.21.4. signal() - Notes](#1214-signal---notes)
	- [1.22. sigaction()](#122-sigaction)
		- [1.22.1. sigaction() - Prototype](#1221-sigaction---prototype)
		- [1.22.2. sigaction() - Expliquations](#1222-sigaction---expliquations)
		- [1.22.3. sigaction() - Exemple](#1223-sigaction---exemple)
		- [1.22.4. sigaction() - Notes](#1224-sigaction---notes)
	- [1.23. sigemptyset()](#123-sigemptyset)
		- [1.23.1. sigemptyset() - Prototype](#1231-sigemptyset---prototype)
		- [1.23.2. sigemptyset() - Expliquations](#1232-sigemptyset---expliquations)
		- [1.23.3. sigemptyset() - Exemple](#1233-sigemptyset---exemple)
		- [1.23.4. sigemptyset() - Notes](#1234-sigemptyset---notes)
	- [1.24. sigaddset()](#124-sigaddset)
		- [1.24.1. sigaddset() - Prototype](#1241-sigaddset---prototype)
		- [1.24.2. sigaddset() - Expliquations](#1242-sigaddset---expliquations)
		- [1.24.3. sigaddset() - Exemple](#1243-sigaddset---exemple)
		- [1.24.4. sigaddset() - Notes](#1244-sigaddset---notes)
	- [1.25. kill()](#125-kill)
		- [1.25.1. kill() - Prototype](#1251-kill---prototype)
		- [1.25.2. kill() - Expliquations](#1252-kill---expliquations)
		- [1.25.3. kill() - Exemple](#1253-kill---exemple)
		- [1.25.4. kill() - Notes](#1254-kill---notes)
	- [1.26. exit()](#126-exit)
		- [1.26.1. exit() - Prototype](#1261-exit---prototype)
		- [1.26.2. exit() - Expliquations](#1262-exit---expliquations)
		- [1.26.3. exit() - Exemple](#1263-exit---exemple)
		- [1.26.4. exit() - Notes](#1264-exit---notes)
	- [1.27. getcwd()](#127-getcwd)
		- [1.27.1. getcwd() - Prototype](#1271-getcwd---prototype)
		- [1.27.2. getcwd() - Expliquations](#1272-getcwd---expliquations)
		- [1.27.3. getcwd() - Exemple](#1273-getcwd---exemple)
		- [1.27.4. getcwd() - Notes](#1274-getcwd---notes)
	- [1.28. chdir()](#128-chdir)
		- [1.28.1. chdir() - Prototype](#1281-chdir---prototype)
		- [1.28.2. chdir() - Expliquations](#1282-chdir---expliquations)
		- [1.28.3. chdir() - Exemple](#1283-chdir---exemple)
		- [1.28.4. chdir() - Notes](#1284-chdir---notes)
	- [1.29. stat()](#129-stat)
		- [1.29.1. stat() - Prototype](#1291-stat---prototype)
		- [1.29.2. stat() - Expliquations](#1292-stat---expliquations)
		- [1.29.3. stat() - Exemple](#1293-stat---exemple)
		- [1.29.4. stat() - Notes](#1294-stat---notes)
	- [1.30. lstat()](#130-lstat)
		- [1.30.1. lstat() - Prototype](#1301-lstat---prototype)
		- [1.30.2. lstat() - Expliquations](#1302-lstat---expliquations)
		- [1.30.3. lstat() - Exemple](#1303-lstat---exemple)
		- [1.30.4. lstat() - Notes](#1304-lstat---notes)
	- [1.31. fstat()](#131-fstat)
		- [1.31.1. fstat() - Prototype](#1311-fstat---prototype)
		- [1.31.2. fstat() - Expliquations](#1312-fstat---expliquations)
		- [1.31.3. fstat() - Exemple](#1313-fstat---exemple)
		- [1.31.4. fstat() - Notes](#1314-fstat---notes)
	- [1.32. unlink()](#132-unlink)
		- [1.32.1. unlink() - Prototype](#1321-unlink---prototype)
		- [1.32.2. unlink() - Expliquations](#1322-unlink---expliquations)
		- [1.32.3. unlink() - Exemple](#1323-unlink---exemple)
		- [1.32.4. unlink() - Notes](#1324-unlink---notes)
	- [1.33. execve()](#133-execve)
		- [1.33.1. execve() - Prototype](#1331-execve---prototype)
		- [1.33.2. execve() - Expliquations](#1332-execve---expliquations)
		- [1.33.3. execve() - Exemple](#1333-execve---exemple)
		- [1.33.4. execve() - Notes](#1334-execve---notes)
	- [1.34. dup()](#134-dup)
		- [1.34.1. dup() - Prototype](#1341-dup---prototype)
		- [1.34.2. dup() - Expliquations](#1342-dup---expliquations)
		- [1.34.3. dup() - Exemple](#1343-dup---exemple)
		- [1.34.4. dup() - Notes](#1344-dup---notes)
	- [1.35. dup2()](#135-dup2)
		- [1.35.1. dup2() - Prototype](#1351-dup2---prototype)
		- [1.35.2. dup2() - Expliquations](#1352-dup2---expliquations)
		- [1.35.3. dup2() - Exemple](#1353-dup2---exemple)
		- [1.35.4. dup2() - Notes](#1354-dup2---notes)
	- [1.36. pipe()](#136-pipe)
		- [1.36.1. pipe() - Prototype](#1361-pipe---prototype)
		- [1.36.2. pipe() - Expliquations](#1362-pipe---expliquations)
		- [1.36.3. pipe() - Exemple](#1363-pipe---exemple)
		- [1.36.4. pipe() - Notes](#1364-pipe---notes)
	- [1.37. opendir()](#137-opendir)
		- [1.37.1. opendir() - Prototype](#1371-opendir---prototype)
		- [1.37.2. opendir() - Expliquations](#1372-opendir---expliquations)
		- [1.37.3. opendir() - Exemple](#1373-opendir---exemple)
		- [1.37.4. opendir() - Notes](#1374-opendir---notes)
	- [1.38. readdir()](#138-readdir)
		- [1.38.1. readdir() - Prototype](#1381-readdir---prototype)
		- [1.38.2. readdir() - Expliquations](#1382-readdir---expliquations)
		- [1.38.3. readdir() - Exemple](#1383-readdir---exemple)
		- [1.38.4. readdir() - Notes](#1384-readdir---notes)
	- [1.39. closedir()](#139-closedir)
		- [1.39.1. closedir() - Prototype](#1391-closedir---prototype)
		- [1.39.2. closedir() - Expliquations](#1392-closedir---expliquations)
		- [1.39.3. closedir() - Exemple](#1393-closedir---exemple)
		- [1.39.4. closedir() - Notes](#1394-closedir---notes)
	- [1.40. strerror()](#140-strerror)
		- [1.40.1. strerror() - Prototype](#1401-strerror---prototype)
		- [1.40.2. strerror() - Expliquations](#1402-strerror---expliquations)
		- [1.40.3. strerror() - Exemple](#1403-strerror---exemple)
		- [1.40.4. strerror() - Notes](#1404-strerror---notes)
	- [1.41. perror()](#141-perror)
		- [1.41.1. perror() - Prototype](#1411-perror---prototype)
		- [1.41.2. perror() - Expliquations](#1412-perror---expliquations)
		- [1.41.3. perror() - Exemple](#1413-perror---exemple)
		- [1.41.4. perror() - Notes](#1414-perror---notes)
	- [1.42. isatty()](#142-isatty)
		- [1.42.1. isatty() - Prototype](#1421-isatty---prototype)
		- [1.42.2. isatty() - Expliquations](#1422-isatty---expliquations)
		- [1.42.3. isatty() - Exemple](#1423-isatty---exemple)
		- [1.42.4. isatty() - Notes](#1424-isatty---notes)
	- [1.43. ttyname()](#143-ttyname)
		- [1.43.1. ttyname() - Prototype](#1431-ttyname---prototype)
		- [1.43.2. ttyname() - Expliquations](#1432-ttyname---expliquations)
		- [1.43.3. ttyname() - Exemple](#1433-ttyname---exemple)
		- [1.43.4. ttyname() - Notes](#1434-ttyname---notes)
	- [1.44. ttyslot()](#144-ttyslot)
		- [1.44.1. ttyslot() - Prototype](#1441-ttyslot---prototype)
		- [1.44.2. ttyslot() - Expliquations](#1442-ttyslot---expliquations)
		- [1.44.3. ttyslot() - Exemple](#1443-ttyslot---exemple)
		- [1.44.4. ttyslot() - Notes](#1444-ttyslot---notes)
	- [1.45. ioctl()](#145-ioctl)
		- [1.45.1. ioctl() - Prototype](#1451-ioctl---prototype)
		- [1.45.2. ioctl() - Expliquations](#1452-ioctl---expliquations)
		- [1.45.3. ioctl() - Exemple](#1453-ioctl---exemple)
		- [1.45.4. ioctl() - Notes](#1454-ioctl---notes)
	- [1.46. getenv()](#146-getenv)
		- [1.46.1. getenv() - Prototype](#1461-getenv---prototype)
		- [1.46.2. getenv() - Expliquations](#1462-getenv---expliquations)
		- [1.46.3. getenv() - Exemple](#1463-getenv---exemple)
		- [1.46.4. getenv() - Notes](#1464-getenv---notes)
	- [1.47. tcsetattr()](#147-tcsetattr)
		- [1.47.1. tcsetattr() - Prototype](#1471-tcsetattr---prototype)
		- [1.47.2. tcsetattr() - Expliquations](#1472-tcsetattr---expliquations)
		- [1.47.3. tcsetattr() - Exemple](#1473-tcsetattr---exemple)
		- [1.47.4. tcsetattr() - Notes](#1474-tcsetattr---notes)
	- [1.48. tcgetattr()](#148-tcgetattr)
		- [1.48.1. tcgetattr() - Prototype](#1481-tcgetattr---prototype)
		- [1.48.2. tcgetattr() - Expliquations](#1482-tcgetattr---expliquations)
		- [1.48.3. tcgetattr() - Exemple](#1483-tcgetattr---exemple)
		- [1.48.4. tcgetattr() - Notes](#1484-tcgetattr---notes)
	- [1.49. tgetent()](#149-tgetent)
		- [1.49.1. tgetent() - Prototype](#1491-tgetent---prototype)
		- [1.49.2. tgetent() - Expliquations](#1492-tgetent---expliquations)
		- [1.49.3. tgetent() - Exemple](#1493-tgetent---exemple)
		- [1.49.4. tgetent() - Notes](#1494-tgetent---notes)
	- [1.50. tgetflag()](#150-tgetflag)
		- [1.50.1. tgetflag() - Prototype](#1501-tgetflag---prototype)
		- [1.50.2. tgetflag() - Expliquations](#1502-tgetflag---expliquations)
		- [1.50.3. tgetflag() - Exemple](#1503-tgetflag---exemple)
		- [1.50.4. tgetflag() - Notes](#1504-tgetflag---notes)
	- [1.51. tgetnum()](#151-tgetnum)
		- [1.51.1. tgetnum() - Prototype](#1511-tgetnum---prototype)
		- [1.51.2. tgetnum() - Expliquations](#1512-tgetnum---expliquations)
		- [1.51.3. tgetnum() - Exemple](#1513-tgetnum---exemple)
		- [1.51.4. tgetnum() - Notes](#1514-tgetnum---notes)
	- [1.52. tgetstr()](#152-tgetstr)
		- [1.52.1. tgetstr() - Prototype](#1521-tgetstr---prototype)
		- [1.52.2. tgetstr() - Expliquations](#1522-tgetstr---expliquations)
		- [1.52.3. tgetstr() - Exemple](#1523-tgetstr---exemple)
		- [1.52.4. tgetstr() - Notes](#1524-tgetstr---notes)
	- [1.53. tgoto()](#153-tgoto)
		- [1.53.1. tgoto() - Prototype](#1531-tgoto---prototype)
		- [1.53.2. tgoto() - Expliquations](#1532-tgoto---expliquations)
		- [1.53.3. tgoto() - Exemple](#1533-tgoto---exemple)
		- [1.53.4. tgoto() - Notes](#1534-tgoto---notes)
	- [1.54. tputs()](#154-tputs)
		- [1.54.1. tputs() - Prototype](#1541-tputs---prototype)
		- [1.54.2. tputs() - Expliquations](#1542-tputs---expliquations)
		- [1.54.3. tputs() - Exemple](#1543-tputs---exemple)
		- [1.54.4. tputs() - Notes](#1544-tputs---notes)

## 1.2. readline()

### 1.2.1. readline() - Prototype

```c
#include <readline/readline.h>

char *readline(const char * prompt);
```

### 1.2.2. readline() - Expliquations

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

### 1.3.2. rl_clear_history() - Expliquations

### 1.3.3. rl_clear_history() - Exemple

### 1.3.4. rl_clear_history() - Notes

## 1.4. rl_on_new_line()

### 1.4.1. rl_on_new_line() - Prototype

### 1.4.2. rl_on_new_line() - Expliquations

### 1.4.3. rl_on_new_line() - Exemple

### 1.4.4. rl_on_new_line() - Notes

## 1.5. rl_replace_line()

### 1.5.1. rl_replace_line() - Prototype

### 1.5.2. rl_replace_line() - Expliquations

### 1.5.3. rl_replace_line() - Exemple

### 1.5.4. rl_replace_line() - Notes

## 1.6. rl_redisplay()

### 1.6.1. rl_redisplay() - Prototype

### 1.6.2. rl_redisplay() - Expliquations

### 1.6.3. rl_redisplay() - Exemple

### 1.6.4. rl_redisplay() - Notes

## 1.7. add_history()

### 1.7.1. add_history() - Prototype

### 1.7.2. add_history() - Expliquations

### 1.7.3. add_history() - Exemple

### 1.7.4. add_history() - Notes

## 1.8. printf()

### 1.8.1. printf() - Prototype

### 1.8.2. printf() - Expliquations

### 1.8.3. printf() - Exemple

### 1.8.4. printf() - Notes

## 1.9. malloc()

### 1.9.1. malloc() - Prototype

### 1.9.2. malloc() - Expliquations

### 1.9.3. malloc() - Exemple

### 1.9.4. malloc() - Notes

## 1.10. free()

### 1.10.1. free() - Prototype

### 1.10.2. free() - Expliquations

### 1.10.3. free() - Exemple

### 1.10.4. free() - Notes

## 1.11. write()

### 1.11.1. write() - Prototype

### 1.11.2. write() - Expliquations

### 1.11.3. write() - Exemple

### 1.11.4. write() - Notes

## 1.12. access()

### 1.12.1. access() - Prototype

### 1.12.2. access() - Expliquations

### 1.12.3. access() - Exemple

### 1.12.4. access() - Notes

## 1.13. open()

### 1.13.1. open() - Prototype

### 1.13.2. open() - Expliquations

### 1.13.3. open() - Exemple

### 1.13.4. open() - Notes

## 1.14. read()

### 1.14.1. read() - Prototype

### 1.14.2. read() - Expliquations

### 1.14.3. read() - Exemple

### 1.14.4. read() - Notes

## 1.15. close()

### 1.15.1. close() - Prototype

### 1.15.2. close() - Expliquations

### 1.15.3. close() - Exemple

### 1.15.4. close() - Notes

## 1.16. fork()

### 1.16.1. fork() - Prototype

### 1.16.2. fork() - Expliquations

### 1.16.3. fork() - Exemple

### 1.16.4. fork() - Notes

## 1.17. wait()

### 1.17.1. wait() - Prototype

### 1.17.2. wait() - Expliquations

### 1.17.3. wait() - Exemple

### 1.17.4. wait() - Notes

## 1.18. waitpid()

### 1.18.1. waitpid() - Prototype

### 1.18.2. waitpid() - Expliquations

### 1.18.3. waitpid() - Exemple

### 1.18.4. waitpid() - Notes

## 1.19. wait3()

### 1.19.1. wait3() - Prototype

### 1.19.2. wait3() - Expliquations

### 1.19.3. wait3() - Exemple

### 1.19.4. wait3() - Notes

## 1.20. wait4()

### 1.20.1. wait4() - Prototype

### 1.20.2. wait4() - Expliquations

### 1.20.3. wait4() - Exemple

### 1.20.4. wait4() - Notes

## 1.21. signal()

### 1.21.1. signal() - Prototype

### 1.21.2. signal() - Expliquations

### 1.21.3. signal() - Exemple

### 1.21.4. signal() - Notes

## 1.22. sigaction()

### 1.22.1. sigaction() - Prototype

### 1.22.2. sigaction() - Expliquations

### 1.22.3. sigaction() - Exemple

### 1.22.4. sigaction() - Notes

## 1.23. sigemptyset()

### 1.23.1. sigemptyset() - Prototype

### 1.23.2. sigemptyset() - Expliquations

### 1.23.3. sigemptyset() - Exemple

### 1.23.4. sigemptyset() - Notes

## 1.24. sigaddset()

### 1.24.1. sigaddset() - Prototype

### 1.24.2. sigaddset() - Expliquations

### 1.24.3. sigaddset() - Exemple

### 1.24.4. sigaddset() - Notes

## 1.25. kill()

### 1.25.1. kill() - Prototype

### 1.25.2. kill() - Expliquations

### 1.25.3. kill() - Exemple

### 1.25.4. kill() - Notes

## 1.26. exit()

### 1.26.1. exit() - Prototype

### 1.26.2. exit() - Expliquations

### 1.26.3. exit() - Exemple

### 1.26.4. exit() - Notes

## 1.27. getcwd()

### 1.27.1. getcwd() - Prototype

### 1.27.2. getcwd() - Expliquations

### 1.27.3. getcwd() - Exemple

### 1.27.4. getcwd() - Notes

## 1.28. chdir()

### 1.28.1. chdir() - Prototype

### 1.28.2. chdir() - Expliquations

### 1.28.3. chdir() - Exemple

### 1.28.4. chdir() - Notes

## 1.29. stat()

### 1.29.1. stat() - Prototype

### 1.29.2. stat() - Expliquations

### 1.29.3. stat() - Exemple

### 1.29.4. stat() - Notes

## 1.30. lstat()

### 1.30.1. lstat() - Prototype

### 1.30.2. lstat() - Expliquations

### 1.30.3. lstat() - Exemple

### 1.30.4. lstat() - Notes

## 1.31. fstat()

### 1.31.1. fstat() - Prototype

### 1.31.2. fstat() - Expliquations

### 1.31.3. fstat() - Exemple

### 1.31.4. fstat() - Notes

## 1.32. unlink()

### 1.32.1. unlink() - Prototype

### 1.32.2. unlink() - Expliquations

### 1.32.3. unlink() - Exemple

### 1.32.4. unlink() - Notes

## 1.33. execve()

### 1.33.1. execve() - Prototype

### 1.33.2. execve() - Expliquations

### 1.33.3. execve() - Exemple

### 1.33.4. execve() - Notes

## 1.34. dup()

### 1.34.1. dup() - Prototype

### 1.34.2. dup() - Expliquations

### 1.34.3. dup() - Exemple

### 1.34.4. dup() - Notes

## 1.35. dup2()

### 1.35.1. dup2() - Prototype

### 1.35.2. dup2() - Expliquations

### 1.35.3. dup2() - Exemple

### 1.35.4. dup2() - Notes

## 1.36. pipe()

### 1.36.1. pipe() - Prototype

### 1.36.2. pipe() - Expliquations

### 1.36.3. pipe() - Exemple

### 1.36.4. pipe() - Notes

## 1.37. opendir()

### 1.37.1. opendir() - Prototype

### 1.37.2. opendir() - Expliquations

### 1.37.3. opendir() - Exemple

### 1.37.4. opendir() - Notes

## 1.38. readdir()

### 1.38.1. readdir() - Prototype

### 1.38.2. readdir() - Expliquations

### 1.38.3. readdir() - Exemple

### 1.38.4. readdir() - Notes

## 1.39. closedir()

### 1.39.1. closedir() - Prototype

### 1.39.2. closedir() - Expliquations

### 1.39.3. closedir() - Exemple

### 1.39.4. closedir() - Notes

## 1.40. strerror()

### 1.40.1. strerror() - Prototype

### 1.40.2. strerror() - Expliquations

### 1.40.3. strerror() - Exemple

### 1.40.4. strerror() - Notes

## 1.41. perror()

### 1.41.1. perror() - Prototype

### 1.41.2. perror() - Expliquations

### 1.41.3. perror() - Exemple

### 1.41.4. perror() - Notes

## 1.42. isatty()

### 1.42.1. isatty() - Prototype

### 1.42.2. isatty() - Expliquations

### 1.42.3. isatty() - Exemple

### 1.42.4. isatty() - Notes

## 1.43. ttyname()

### 1.43.1. ttyname() - Prototype

### 1.43.2. ttyname() - Expliquations

### 1.43.3. ttyname() - Exemple

### 1.43.4. ttyname() - Notes

## 1.44. ttyslot()

### 1.44.1. ttyslot() - Prototype

### 1.44.2. ttyslot() - Expliquations

### 1.44.3. ttyslot() - Exemple

### 1.44.4. ttyslot() - Notes

## 1.45. ioctl()

### 1.45.1. ioctl() - Prototype

### 1.45.2. ioctl() - Expliquations

### 1.45.3. ioctl() - Exemple

### 1.45.4. ioctl() - Notes

## 1.46. getenv()

### 1.46.1. getenv() - Prototype

### 1.46.2. getenv() - Expliquations

### 1.46.3. getenv() - Exemple

### 1.46.4. getenv() - Notes

## 1.47. tcsetattr()

### 1.47.1. tcsetattr() - Prototype

### 1.47.2. tcsetattr() - Expliquations

### 1.47.3. tcsetattr() - Exemple

### 1.47.4. tcsetattr() - Notes

## 1.48. tcgetattr()

### 1.48.1. tcgetattr() - Prototype

### 1.48.2. tcgetattr() - Expliquations

### 1.48.3. tcgetattr() - Exemple

### 1.48.4. tcgetattr() - Notes

## 1.49. tgetent()

### 1.49.1. tgetent() - Prototype

### 1.49.2. tgetent() - Expliquations

### 1.49.3. tgetent() - Exemple

### 1.49.4. tgetent() - Notes

## 1.50. tgetflag()

### 1.50.1. tgetflag() - Prototype

### 1.50.2. tgetflag() - Expliquations

### 1.50.3. tgetflag() - Exemple

### 1.50.4. tgetflag() - Notes

## 1.51. tgetnum()

### 1.51.1. tgetnum() - Prototype

### 1.51.2. tgetnum() - Expliquations

### 1.51.3. tgetnum() - Exemple

### 1.51.4. tgetnum() - Notes

## 1.52. tgetstr()

### 1.52.1. tgetstr() - Prototype

### 1.52.2. tgetstr() - Expliquations

### 1.52.3. tgetstr() - Exemple

### 1.52.4. tgetstr() - Notes

## 1.53. tgoto()

### 1.53.1. tgoto() - Prototype

### 1.53.2. tgoto() - Expliquations

### 1.53.3. tgoto() - Exemple

### 1.53.4. tgoto() - Notes

## 1.54. tputs()

### 1.54.1. tputs() - Prototype

### 1.54.2. tputs() - Expliquations

### 1.54.3. tputs() - Exemple

### 1.54.4. tputs() - Notes
