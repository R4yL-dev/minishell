# Builtins:

> A builtin (or builtin command, or shell builtin) is a command or function that is part of the shell itself.
> The command is "built-in" to the shell program — no external program is necessary to run the command,
> and a new process does not need to be created.
>
> a built-in command can affect the internal state of the shell. That's why commands like cd must be built-in,
> because an external program can't change the current directory of the shell. Other commands,
> like echo, might be built-in for efficiency, but there's no intrinsic reason they can't be external commands.


### ECHO:

> Synthax: `echo [ OPTION(S) ] [ STRING ]`. (we only have to manage -n option)

###### Using variable in `echo` command:

> The value of the variable can be printed with other string in the `echo` command by placing the variable in the text. But one thing you should remember when using the variable in the echo command, that is you must enclose the variable within double quotation(“) to read the value of the variable by `echo` command. If single quotation(‘) is used in the echo command then the value of the variable will not be parsed and the variable name will be printed as output.

###### Using `echo -n` command:

> Omit the newline (\n) at the end.


### CD:

> Synthax: `cd [ Options ] [ Directory ]`. (only with relative or absolut path)

###### Using `cd` command:

> If directory is given, changes the shell's working directory todirectory. If not, changes to HOME (shell variable).

> ./ or just . is shorthand for the current directory. 

>   The shell variable CDPATH provides a useful feature, this variable is similar to PATH but it sets up a list of paths where cd will search for subdirectories. CDPATH can be set on the command line for use in the current session, or in .bash_profile for permanent use, the list of 

>  paths must be colon separated (:)

> If dir begins with a slash (/), then CDPATH is not used.

>   If a non-empty directory name from CDPATH is used, or if - is the first argument, and the directory change is successful, the absolute pathname of the new working directory is written to the standard output.

> The return status is zero if the directory is successfully changed, non-zero otherwise.


### PWD:

> Synthax: `pwd [ OPTION(S) ]`. (we dont have to manage any option here)

###### Using `pwd` command:

> The default action is to show the current folder as an absolute path.
> All components of the path will be actual folder names - none will be symbolic links.

> Some shells provide a builtin pwd command which is similar or identical to this utility.


### EXPORT:

> Synthax: `export [ OPTION(S) ] [ name[=value] ... ]`. (we dont need any option here)

###### Using `export` command:

> It is used to ensure the environment variables and functions to be passed to child processes. It does not affect the existing environment variable.

> Environment variables are set when we open a new shell session. At any time, if we change any variable value, the shell has no way to select that change. The export command allows us to update the current session about the changes that have been made to the exported variable. We do not need to wait to start a new shell session.

### UNSET:

> Synthax: `unset [ OPTION(S) ] [ name ... ]`. (we dont need to manage any option)

###### Using `unset` command:

> For each NAME, remove the corresponding variable or function.
> Without options, unset first tries to unset a variable, and if that fails,
    tries to unset a function.
> Some variables cannot be unset; also see `readonly'.
> Returns success unless an invalid option is given or a NAME is read-only.

### ENV:

> Synthax: `env [ OPTION(S) ]... [ NAME=VALUE ]... [ COMMAND [ ARGS ]... ]`. (we dont need to manage any option or argument)

###### Using `env` command:

> `env` lists all the environment variables.


### EXIT:

> Synthax: `exit [ STATUS_NB ]`.

###### Using `exit` command:

The exit command exits the shell with a STATUS_NB.





