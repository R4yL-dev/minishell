# MiniShell

### Introduction:

* `Minishell` is the first group project we have to do at 42lausanne.
  This project makes you code a minimalistic shell following bash behaviour in C.

* As we can choose our teammate, the team will be composed of lray (@Ray-cmd) & mflury (@FizzYxWizzY).

### Installation:

1. First, git clone the repository:
   - `git clone https://github.com/Ray-cmd/minishell Minishell_42`
1. Then, compile the project at the root of the repository:
   - `make`
1. Finally, launch the minishell:
   - `./minishell`

### How does it works:

+ Minishell gives you a prompt while waiting for commands.

+ It checks if all the passed arguments are valid and makes an `abstract syntax tree` out of them. categorizing them such as `command`, `argument`, `file`, `redirection` and `pipe`.

+ Then it runs executables if it can find a valid path to them using the environement variable `$PATH` or by their path dirctly. (eg: `ls` and `/bin/ls` basically giving the same result)

+ Otherwise, it looks if its a builtins, such as `echo`, `cd`, `pwd`, `export`, `unset`, `env` and `exit`.

+ Minishell also have to manage some signals, such as `Ctrl-C`, `Ctrl-D` and `Ctrl-\` that should reproduce bash behavior.

### Particularities:

+ The `readline` function has leaks that we dont have to correct for the project.

...

> help markdown readme
>
> https://docs.github.com/fr/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax