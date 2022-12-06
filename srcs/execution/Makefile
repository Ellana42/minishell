NAME	= pipex

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC			=	-I ./includes/\
				-I ./libft/\

SRC_PATH = srcs/
OBJ_PATH = obj/

SRC	= main.c \
	paths.c \
	utils.c \
	init.c \
	here_doc.c \
	get_next_line.c \
	get_next_line_utils.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

INC		= -I ./includes/

all: $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)get_next_line/
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean