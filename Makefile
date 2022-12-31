NAME  = minishell

SRCS  =  srcs/main.c \
	srcs/glob.c \
	srcs/glob_env.c \
	srcs/glob_env_get.c \
	srcs/glob_set_env.c \
	srcs/builtins/echo/echo.c \
	srcs/builtins/exit/exit.c \
	srcs/builtins/pwd/pwd.c \
	srcs/builtins/env/env.c \
	srcs/builtins/cd/cd.c \
	srcs/builtins/export/export.c \
	srcs/builtins/export/export_arg.c \
	srcs/builtins/exit/atoi.c \
	srcs/builtins/unset/unset.c \
	srcs/execution/executable/destroy.c \
	srcs/execution/executable/print.c \
	srcs/execution/executable/close_unused.c \
	srcs/execution/executable/init.c \
	srcs/execution/executable/get_fd.c \
	srcs/execution/executable/get.c \
	srcs/execution/executable/close.c \
	srcs/execution/paths_utils.c \
	srcs/execution/destroy.c \
	srcs/execution/print.c \
	srcs/execution/pipes.c \
	srcs/execution/here_doc.c \
	srcs/execution/launch_builtin.c \
	srcs/execution/close_unused_fds.c \
	srcs/execution/close_utils.c \
	srcs/execution/executables/destroy.c \
	srcs/execution/executables/print.c \
	srcs/execution/executables/init.c \
	srcs/execution/executables/get.c \
	srcs/execution/init.c \
	srcs/execution/execute.c \
	srcs/execution/get_fd_pipe.c \
	srcs/execution/set.c \
	srcs/execution/get2.c \
	srcs/execution/get.c \
	srcs/execution/redirections.c \
	srcs/execution/close_fds.c \
	srcs/execution/get_paths.c \
	srcs/execution/execution.c \
	srcs/execution/clean_redirections.c \
	srcs/execution/int_list/print.c \
	srcs/execution/int_list/clear.c \
	srcs/execution/int_list/new.c \
	srcs/execution/dup.c \
	srcs/glob_init.c \
	srcs/glob_get.c \
	srcs/parsing/parsing.c \
	srcs/parsing/tokenizer/acc_var.c \
	srcs/parsing/tokenizer/accumulator.c \
	srcs/parsing/tokenizer/display.c \
	srcs/parsing/tokenizer/check.c \
	srcs/parsing/tokenizer/push.c \
	srcs/parsing/tokenizer/init.c \
	srcs/parsing/tokenizer/move.c \
	srcs/parsing/tokenizer/token.c \
	srcs/parsing/tokenizer/get.c \
	srcs/parsing/tokenizer/token_init2.c \
	srcs/parsing/tokenizer/push_funnels.c \
	srcs/parsing/tokenizer/get_tokens.c \
	srcs/parsing/tokenizer/token_init.c \
	srcs/parsing/tokenizer/token_print.c \
	srcs/parsing/utils/table.c \
	srcs/parsing/utils/mem.c \
	srcs/parsing/utils/str.c \
	srcs/parsing/parser/init.c \
	srcs/parsing/parser/move.c \
	srcs/parsing/parser/get.c \
	srcs/parsing/parser/parse_funnels.c \
	srcs/parsing/parser/tokenize.c \
	srcs/parsing/parser/parse.c \
	srcs/parsing/parser/errors.c \
	srcs/parsing/accumulator/init.c \
	srcs/parsing/accumulator/move.c \
	srcs/parsing/accumulator/set.c \
	srcs/parsing/accumulator/get.c \
	srcs/parsing/commands/get_1.c \
	srcs/parsing/commands/print.c \
	srcs/parsing/commands/get1.c \
	srcs/parsing/commands/push.c \
	srcs/parsing/commands/init.c \
	srcs/parsing/commands/get.c \
	srcs/parsing/commands/free.c \
	srcs/parsing/command/add_1.c \
	srcs/parsing/command/print.c \
	srcs/parsing/command/init.c \
	srcs/parsing/command/get2.c \
	srcs/parsing/command/get.c \
	srcs/parsing/command/funnel.c \
	srcs/parsing/command/free.c \
	srcs/parsing/command/add.c \
	srcs/parsing/lstutils/str_chain.c \
	srcs/parsing/lstutils/get.c \
	srcs/parsing/tokenize/single_quote.c \
	srcs/parsing/tokenize/noquote.c \
	srcs/parsing/tokenize/noquote_chars.c \
	srcs/parsing/tokenize/quote.c \
	srcs/parsing/tokenize/tokenize.c \
	srcs/parsing/tokenize/noquote_funnels.c \
	srcs/glob_set.c \
	srcs/signals.c 

OBJS  = ${SRCS:.c=.o}

HEADERS	= includes/minishell.h

CC	= clang

CFLAGS	= -g3 #-Wall -Wextra -Werror

LIBFT	= -L libft -lft

VALGRIND = colour-valgrind 

all: 		lib ${NAME} 

${NAME}: 	${OBJS}
			${CC} ${CFLAGS} -lreadline ${OBJS} ${LIBFT} -o ${NAME}

.c.o:		
			${CC} ${CFLAGS} -I${HEADERS} -c $< -o $@

lib:		
			make -C libft

clean:		
			rm -f ${OBJS} 
			make -C libft clean

fclean:		clean
			rm -f ${NAME}
			make -C libft fclean

re:			fclean all

norm:	
			norminette -R CheckSourceHeader ${SRCS}

.PHONY :	all clean fclean re norm 
