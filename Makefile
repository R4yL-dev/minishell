NAME		:= minishell

SRCS 		:= \
	ctx/ctx.c \
	vars/var.c \
	vars/lstvar.c \
	vars/lstvar_to_array.c \
	vars/grpvar.c \
	builtins/lstbuiltins.c \
	builtins/lstbuiltins_has.c \
	builtins/lstbuiltins_exec.c \
	builtins/test.c \
	builtins/echo.c \
	builtins/pwd.c \
	builtins/exit.c \
	builtins/clear.c \
	prompt/prompt.c \
	lexer/lexer.c \
	lexer/lexer_utils.c \
	lexer/token.c \
	lexer/dyntklist.c \
	lexer/dyntklist_split.c \
	parser/parser.c \
	parser/dyntree.c \
	expand/expand.c \
	expand/replace_var.c\
	expand/replace_builtins.c \
	exec/exec.c \
	exec/pipes_list.c \
	exec/env_node.c \
	exec/dynarrstr.c \
	exec/open_file.c \
	exec/get_cmd_path.c \
	exec/make_argv.c \
	exec/get_infd.c \
	exec/get_outfd.c \
	signals/signals.c \
	utils.c \
	main.c \
	debug.c

OBJS		:= $(SRCS:.c=.o)

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -std=gnu89 -fsanitize=address,undefined -static-libasan -fno-omit-frame-pointer -g
CPPFLAGS	:= -Ireadline/include/readline/ -lreadline -Lreadline/lib -Ilibft -Iprompt -Ilexer

LIBS		:= \
	./libft/libft.a

RM			:= rm -f
MAKEFLAGS   += --no-print-directory

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft/
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LIBS) -o $(NAME)
	$(info CREATED $(NAME))

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(info CREATED $@)

clean :
	@make clean -C libft/
	$(RM) $(OBJS)
	$(info DELETED objects files)

fclean : clean
	@make fclean -C libft/
	$(RM) $(NAME)
	$(info DELETED $(NAME))

re :
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

.PHONY : clean fclean re info-
.SILENT :
