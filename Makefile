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
	builtins/showctx.c \
	builtins/echo.c \
	builtins/pwd.c \
	builtins/exit.c \
	builtins/clear.c \
	prompt/prompt.c \
	lexer/lexer.c \
	lexer/add_redirect.c \
	lexer/add_to_tklist.c \
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
	exec/exec_cmd.c \
	exec/exec_piped_cmd.c \
	exec/pipes_list.c \
	exec/env.c \
	exec/dynarrstr.c \
	exec/make_env.c \
	exec/exec_env.c \
	exec/open_file.c \
	exec/get_cmd_path.c \
	exec/is_an_executable.c \
	exec/make_argv.c \
	exec/get_infd.c \
	exec/get_outfd.c \
	exec/make_heredoc.c \
	signals/set_sigmode.c \
	signals/handle_sigint.c \
	signals/handle_sigint_heredoc.c \
	signals/handle_sigquit.c \
	signals/handle_sigquit_heredoc.c \
	utils.c \
	main.c

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
