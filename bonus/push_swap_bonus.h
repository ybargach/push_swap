/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:23:25 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/17 14:23:25 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

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
	int		index;
	int		index_1;
	int		index_2;
	int		save1;
	int		save2;
	long	low_number1;
	long	low_number2;
	long	high_number1;
	long	high_number2;
	char	*data;
	char	*get;
	t_stack	*newnode;
	t_stack	*secondnode;
}	t_data;

//BONUS

int		ft_strcmp(char *s1, char *s2);
void	main_checker(t_stack **a, t_stack **b);
int		checker_bonus(t_stack **a, t_stack **b, t_data arr);
void	checker_sort(t_stack **a, t_stack **b, t_data arr);
int		check_sort_bonus(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);

//t_stack

void	add_back(t_stack **elem, int value);
void	add_first(t_stack **elem, int value);
void	free_node(t_stack **elem);
void	put_in_stack(int *number, int c);
int		stack_size(t_stack *elem);
void	push(t_stack **src, t_stack **dst);
void	rra(t_stack **elem);
void	ra(t_stack **data);
void	sa(t_stack **elem);
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

// get_next_line

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(char *stock, int fd);
char	*ft_line(char *str);
char	*ft_save(char *str);
char	*ft_strchr(char *str, int c);

#endif