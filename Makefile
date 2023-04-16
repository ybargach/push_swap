SRC = function.c check_number.c get_next_space_utils.c \
		get_next_space.c push_swap.c push_A_to_B.c \

OBJ =$(SRC:.c=.o)
.SILENT:

CC = gcc
CFLAGS = -fsanitize=address -g3 -o push_swap

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