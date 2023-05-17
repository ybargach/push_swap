# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 18:56:23 by ybargach          #+#    #+#              #
#    Updated: 2023/05/17 16:22:39 by ybargach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_error.c check_number.c function_utils.c \
		function.c push_swap.c push_A_to_B.c push_B_to_A.c \
		parsing_stack_a.c parsing_stack_b.c push_to_stack.c \
		sort_five.c sort_five_utils.c function_utils_2.c sort_data.c \

BONUS = bonus/check_error_bonus.c bonus/check_number_bonus.c bonus/function_utils_bonus.c \
			bonus/function_bonus.c bonus/push_swap_bonus.c \
			bonus/parsing_stack_a_bonus.c bonus/parsing_stack_b_bonus.c \
			bonus/push_to_stack_bonus.c bonus/function_utils_2_bonus.c \
			bonus/get_next_line.c bonus/get_next_line_utils.c bonus/check_sort_bonus.c \

NAME = push_swap
CHECKER = checker

OBJ = $(SRC:.c=.o)
OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(CHECKER)

clean:
	rm -f $(OBJ) $(OBJS)

fclean:
	rm -f $(OBJ) $(NAME) $(CHECKER) $(OBJS)

re: fclean all