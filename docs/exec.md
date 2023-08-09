# Exécution

## Input

`L'arbre magique` (`ls -l < input.txt | grep "file.txt | sort > output.txt`).

### ToDo

```text
Sub 1
	InFD	: input.txt
	OutFD	: first pipe in
	Exec	: "ls -l"

Sub 2
	InFD	: first pipe out
	OutFD	: second pipe in
	Exec	: "grep file.txt"

Sub 3
	InFD	: second pipe out
	OutFD	: output.txt
	Exec	: sort
```
