/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_A_to_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:56:38 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/12 09:29:43 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_array(t_stack **elem, t_stack **node, t_data arr)
{
	int	i;
	int	j;

	i = 0;
	arr.a = 0;
	while (i < arr.arr_size)
	{
		j = i;
		while (j < (i + arr.chunk_size) && j < arr.arr_size)
			j++;
		arr.a++;
		i = i + arr.chunk_size;
	}
	check_less(elem, node, arr);
}

void	push_data_to_b(t_stack **a, t_stack **b, t_data arr)
{
	int	size;
	int	i;
	int	save;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		if ((*a)->x <= arr.max_number)
		{
			save = (*a)->x;
			push(a, b);
			if (save > arr.mid_number)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
}

void	check_less(t_stack **elem, t_stack **node, t_data arr)
{
	int	a;
	int	start;
	int	end;

	a = 1;
	start = 0;
	end = 0;
	arr.max_number = 0;
	arr.mid_number = 0;
	while (a <= arr.a)
	{
		end = arr.chunk_size * a;
		if (end > arr.arr_size)
			end = arr.arr_size;
		start = end - arr.chunk_size;
		arr.max_number = arr.number[end - 1];
		arr.mid_number = arr.number[start + (arr.chunk_size / 2)];
		push_data_to_b(elem, node, arr);
		a++;
	}
}

void	lower_half(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = 0;
	arr.b = 0;
	if (arr.index_1 > arr.index_2)
	{
		while (arr.a < arr.index_2)
			(rb(b), arr.b++, arr.a++);
		push_b(b, a);
		while (arr.a < (arr.index_1 - 1))
			(rb(b), arr.a++);
		push_b(b, a);
		sa(a);
	}
	else if (arr.index_1 < arr.index_2)
	{
		while (arr.a < arr.index_1)
			(rb(b), arr.a++);
		push_b(b, a);
	}
}
