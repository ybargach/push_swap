/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:57:07 by ybargach          #+#    #+#             */
/*   Updated: 2023/04/18 01:57:48 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **elem)
{
	t_stack	*lastnode;

	lastnode = last_node(elem);
	if ((*elem)->x > (*elem)->next->x)
		sa(elem);
	if ((*elem)->next->x > lastnode->x)
		rra(elem);
	if ((*elem)->x > (*elem)->next->x)
		sa(elem);
}

void	sort_five(t_stack **elem, t_stack **node, int index)
{
	int		a;
	int		*number;
	t_stack	*newnode;
	t_data	arr;

	a = 0;
	number = malloc(index * sizeof(int));
	arr.number = number;
	newnode = *elem;
	while (a < index)
	{
		arr.number[a] = newnode->x;
		newnode = newnode->next;
		a++;
	}
	check_sort(arr, index);
	push_five_a_to_b(elem, node, arr);
}

void	sort_one_hundred(t_stack **elem, t_stack **node, int index)
{
	int		a;
	int		*number;
	t_stack	*newnode;
	t_data	array;

	a = 0;
	number = malloc(index * sizeof(int));
	array.number = number;
	array.arr_size = index;
	array.chunk_size = array.arr_size / 3;
	newnode = (*elem);
	while (a < index)
	{
		array.number[a] = newnode->x;
		newnode = newnode->next;
		a++;
	}
	check_sort(array, index);
	chunk_array(elem, node, array);
	push_b_to_a(elem, node, array);
}

void	sort_five_hundred(t_stack **elem, t_stack **node, int index)
{
	int		a;
	int		*number;
	t_stack	*newnode;
	t_data	array;

	a = 0;
	number = malloc(index * sizeof(int));
	array.number = number;
	array.arr_size = index;
	array.chunk_size = array.arr_size / 8;
	newnode = (*elem);
	while (a < index)
	{
		array.number[a] = newnode->x;
		newnode = newnode->next;
		a++;
	}
	check_sort(array, index);
	chunk_array(elem, node, array);
	push_b_to_a(elem, node, array);
}
