/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:57:16 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/09 11:58:06 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_five_a_to_b(t_stack **elem, t_stack **node, t_data arr)
{
	arr.newnode = *elem;
	arr.arr_size = stack_size(arr.newnode);
	arr.b = 0;
	while (arr.b < arr.arr_size)
	{
		arr.new_arr_size = stack_size(*elem);
		if (arr.new_arr_size <= 3)
			break ;
		min_number(elem, node, arr);
		arr.b++;
	}
	sort_three(elem);
	push_five_b_to_a(elem, node, arr);
}

void	push_five_b_to_a(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = 0;
	arr.arr_size = stack_size(*b);
	while (arr.a < arr.arr_size)
	{
		push_b(b, a);
		arr.a++;
	}
}

void	min_number(t_stack **elem, t_stack **node, t_data arr)
{
	arr.low_number1 = 2147483649;
	arr.low_number2 = 2147483649;
	arr.index_1 = -1;
	arr.index_2 = -1;
	arr.move = 0;
	arr.newnode = *elem;
	while (arr.newnode)
	{
		if (arr.low_number1 > arr.newnode->x)
		{
			arr.low_number2 = arr.low_number1;
			arr.low_number1 = arr.newnode->x;
			arr.index_2 = arr.index_1;
			arr.index_1 = arr.move;
		}
		else if (arr.low_number2 > arr.newnode->x)
		{
			arr.low_number2 = arr.newnode->x;
			arr.index_2 = arr.move;
		}
		arr.move++;
		arr.newnode = arr.newnode->next;
	}
	check_lower_number(elem, node, arr);
}

void	check_lower_number(t_stack **a, t_stack **b, t_data arr)
{
	if (arr.index_1 <= (arr.new_arr_size / 2)
		&& arr.index_2 <= (arr.new_arr_size / 2))
		five_lower(a, b, arr);
	else if (arr.index_1 >= (arr.new_arr_size / 2)
		&& arr.index_2 >= (arr.new_arr_size / 2))
		five_higher(a, b, arr);
	else if (arr.index_1 >= (arr.new_arr_size / 2)
		&& arr.index_2 <= (arr.new_arr_size / 2))
		top_five_higher(a, b, arr);
	else if (arr.index_1 <= (arr.new_arr_size / 2)
		&& arr.index_2 >= (arr.new_arr_size / 2))
		top_five_lower(a, b, arr);
}

void	top_five_higher_equal(t_stack **a, t_stack **b, t_data arr)
{
	arr.a = 0;
	arr.b = 0;
	while (arr.a < (arr.new_arr_size - arr.index_1))
		(rra(a), arr.a++, arr.b++);
	push(a, b);
		arr.a = 0;
	while (arr.a < arr.index_2 + arr.b - 1)
		(ra(a), arr.a++);
	push(a, b);
}
