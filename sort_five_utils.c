/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:55:14 by ybargach          #+#    #+#             */
/*   Updated: 2023/04/18 02:33:19 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_five_lower_equal(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = 0;
	arr.b = 0;
	while (arr.a < arr.index_1)
		(ra(a), arr.a++, arr.b++);
	push(a, b);
	arr.a = 0;
	while (arr.a < (arr.new_arr_size - arr.index_2 + arr.b))
		(rra(a), arr.a++);
	push(a, b);
}

void	top_five_higher(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = 0;
	arr.b = 0;
	if ((arr.new_arr_size - arr.index_1) < arr.index_2)
	{
		while (arr.a < (arr.new_arr_size - arr.index_1))
			(rra(a), arr.a++, arr.b++);
		push(a, b);
		arr.a = 0;
		while (arr.a < arr.index_2 + arr.b)
			(ra(a), arr.a++);
		push(a, b);
	}
	else if ((arr.new_arr_size - arr.index_1) > arr.index_2)
	{
		while (arr.a < arr.index_2)
			(ra(a), arr.a++, arr.b++);
		push(a, b);
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - arr.index_1 + arr.b))
			(rra(a), arr.a++);
		push(a, b);
		sb(b);
	}
	else if ((arr.new_arr_size - arr.index_1) == arr.index_2)
		top_five_higher_equal(a, b, arr);
}

void	top_five_lower(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = 0;
	arr.b = 0;
	if (arr.index_1 < (arr.new_arr_size - arr.index_2))
	{
		while (arr.a < arr.index_1)
			(ra(a), arr.a++, arr.b++);
		push(a, b);
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - arr.index_2 + arr.b))
			(rra(a), arr.a++);
		push(a, b);
	}
	else if (arr.index_1 > (arr.new_arr_size - arr.index_2))
	{
		while (arr.a < (arr.new_arr_size - arr.index_2))
			(rra(a), arr.a++, arr.b++);
		push(a, b);
		arr.a = 0;
		while (arr.a < (arr.index_1 + arr.b - 1))
			(ra(a), arr.a++);
		push(a, b);
		sb(b);
	}
	else if (arr.index_1 == (arr.new_arr_size - arr.index_2))
		top_five_lower_equal(a, b, arr);
}

void	five_lower(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = 0;
	arr.b = 0;
	if (arr.index_1 < arr.index_2)
	{
		while (arr.a < arr.index_1)
			(ra(a), arr.a++, arr.b++);
		push(a, b);
		while (arr.a < arr.index_2 - 1)
			(ra(a), arr.a++);
		push(a, b);
	}
	else
	{
		while (arr.a < arr.index_2)
			(ra(a), arr.a++, arr.b++);
		push(a, b);
		while (arr.a < arr.index_1 - 1)
			(ra(a), arr.a++);
		push(a, b);
		sb(b);
	}
}

void	five_higher(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = 0;
	arr.b = 0;
	if (arr.index_1 > arr.index_2)
	{
		while (arr.a < (arr.new_arr_size - arr.index_1))
			(rra(a), arr.a++, arr.b++);
		push(a, b);
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - (arr.index_2 + arr.b)))
			(rra(a), arr.a++);
		push(a, b);
	}
	else
	{
		while (arr.a < (arr.new_arr_size - arr.index_2))
			(rra(a), arr.a++, arr.b++);
		push(a, b);
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - arr.index_1 - arr.b))
			(rra(a), arr.a++);
		push(a, b);
		sb(b);
	}
}
