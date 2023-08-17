NAME		:= minishell

SRCS 		:= \
	prompt/prompt.c \
	lexer/lexer.c \
	lexer/trim_and_condense_string.c \
	lexer/token.c \
	lexer/dyntklist.c \
	parser/parser.c \
	parser/dyntree.c \
	exec/exec.c \
	exec/dynarrstr.c \
	env/path.c \
	utils.c \
	main.c \
	debug.c

OBJS		:= $(SRCS:.c=.o)

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -std=gnu89 -g
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
