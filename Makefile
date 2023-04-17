SRC = check_error.c check_number.c get_next_space_utils.c \
		get_next_space.c push_swap.c push_A_to_B.c push_B_to_A.c \
		parsing_stack_a.c parsing_stack_b.c push_to_stack.c sort_data.c \

OBJ =$(SRC:.c=.o)
.SILENT:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -o push_swap

all: 
	$(CC) $(CFLAGS) $(SRC)

$(NAME): $(OBJ)
	@ $(CC) $(OBJ) -o $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all