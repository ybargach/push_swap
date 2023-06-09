/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:24:05 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/18 10:49:21 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] || s2[a])
	{
		if (!((unsigned char)s1[a] == (unsigned char)s2[a]))
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return (0);
}

int	check_sort_bonus(t_stack **a)
{
	t_stack	*newnode;

	newnode = *a;
	while (newnode->next)
	{
		if (newnode->x > newnode->next->x)
			return (1);
		newnode = newnode->next;
	}
	return (0);
}

void	checker_sort(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = check_sort_bonus(a);
	if ((*b) == NULL)
	{
		if (arr.a == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "KO\n", 3);
	exit(0);
}

int	checker_bonus(t_stack **a, t_stack **b, t_data arr)
{
	if (ft_strcmp(arr.get, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(arr.get, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(arr.get, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(arr.get, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(arr.get, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(arr.get, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(arr.get, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(arr.get, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(arr.get, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(arr.get, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(arr.get, "pa\n") == 0)
		push_b(b, a);
	else
		return (1);
	return (0);
}

void	main_checker(t_stack **a, t_stack **b)
{
	t_data	arr;

	arr.get = get_next_line(0);
	arr.b = 0;
	while (arr.get)
	{
		if (checker_bonus(a, b, arr) != 0)
		{
			write(1, "Error\n", 6);
			free(arr.get);
			exit(0);
		}
		free(arr.get);
		arr.get = get_next_line(0);
	}
	checker_sort(a, b, arr);
}
