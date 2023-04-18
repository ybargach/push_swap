/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:31:45 by ybargach          #+#    #+#             */
/*   Updated: 2023/04/17 20:31:45 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct stack {
	int				x;
	struct stack	*next;
}	t_stack;

typedef struct data {
	int		a;
	int		b;
	int		c;
	int		*number;
	int		arr_size;
	int		new_arr_size;
	int		chunk_size;
	int		mid_number;
	int		max_number;
	int		move;
	int		index_1;
	int		index_2;
	int		save1;
	int		save2;
	long	low_number1;
	long	low_number2;
	long	high_number1;
	long	high_number2;
	t_stack	*newnode;
	t_stack	*secondnode;
}	t_data;

//t_stack

void	push_five_a_to_b(t_stack **elem, t_stack **node, t_data arr);
void	push_five_b_to_a(t_stack **a, t_stack **b, t_data arr);
void	push_b_to_a(t_stack **elem, t_stack **node, t_data arr);
void	min_number(t_stack **elem, t_stack **node, t_data arr);
void	check_lower_number(t_stack **a, t_stack **b, t_data arr);
void	top_five_higher_equal(t_stack **a, t_stack **b, t_data arr);
void	top_five_lower_equal(t_stack **a, t_stack **b, t_data arr);
void	top_five_higher(t_stack **a, t_stack **b, t_data arr);
void	top_five_lower(t_stack **a, t_stack **b, t_data arr);
void	five_lower(t_stack **a, t_stack **b, t_data arr);
void	five_higher(t_stack **a, t_stack **b, t_data arr);
void	chunk_array(t_stack **elem, t_stack **node, t_data arr);
void	push_data_to_b(t_stack **a, t_stack **b, t_data arr);
void	check_less(t_stack **elem, t_stack **node, t_data arr);
void	max_number(t_stack **elem, t_stack **node, t_data arr);
void	check_higher_lower(t_stack **a, t_stack **b, t_data arr);
void	top_number_in_lower(t_stack **a, t_stack **b, t_data arr);
void	top_number_in_higher(t_stack **a, t_stack **b, t_data arr);
void	higher_half(t_stack **a, t_stack **b, t_data arr);
void	lower_half(t_stack **a, t_stack **b, t_data arr);
void	add_back(t_stack **elem, int value);
void	add_first(t_stack **elem, int value);
void	free_node(t_stack **elem);
void	sort_three(t_stack **elem);
void	sort_five(t_stack **elem, t_stack **node, int index);
void	put_in_stack(int *number, int c, int f);
void	check_index(t_stack **A, t_stack **B, int index);
void	sort_one_hundred(t_stack **elem, t_stack **node, int index);
void	sort_five_hundred(t_stack **elem, t_stack **node, int index);
int		stack_size(t_stack *elem);
void	push(t_stack **src, t_stack **dst);
void	rra(t_stack **elem);
void	ra(t_stack **data);
void	sa(t_stack **elem);
void	push_B_to_A(t_stack **elem, t_stack **node, t_data arr);
void	push_b(t_stack **src, t_stack **dst);
void	rb(t_stack **data);
void	rrb(t_stack **elem);
void	sb(t_stack **elem);
t_stack	*last_node(t_stack **elem);
t_stack	*create_node(int value);

//check

int		ft_strlent(char *str);
void	check_all(char **av, int ac, int f);
int		lenght_array(char **av);
void	check_count(int count);
void	check_sort(t_data res, int index);
void	check_op(const char *str);
void	ft_isdigit(char *str);
void	check_repeated(int *number, int i);
int		check_int(long res);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	put_error(char **arr);

//split

int		first(char const *s1, char const *s2);
int		last(char const *s1, char const *s2);
int		end(char *str, char c, int i);
char	*trim(char const *s, char c);
int		ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
int		start(char *str, char c, int i);
int		word(char const *str, char c);
void	ft_free_arr(char **arr);

#endif