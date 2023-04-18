# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 18:56:23 by ybargach          #+#    #+#              #
#    Updated: 2023/04/18 01:15:06 by ybargach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_error.c check_number.c function_utils.c \
		function.c push_swap.c push_A_to_B.c push_B_to_A.c \
		parsing_stack_a.c parsing_stack_b.c push_to_stack.c \
		sort_five.c sort_five_utils.c function_utils_2.c sort_data.c \

OBJ =$(SRC:.c=.o)
.SILENT:

CC = gcc
CFLAGS = -o push_swap

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