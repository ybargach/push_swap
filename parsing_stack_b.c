/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:56:30 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/17 21:11:11 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_to_a(t_stack **elem, t_stack **node, t_data arr)
{
	t_stack	*newnode;

	newnode = *node;
	arr.arr_size = stack_size(newnode);
	arr.b = 0;
	while (arr.b < arr.arr_size)
	{
		if (node == NULL)
			break ;
		arr.new_arr_size = stack_size(*node);
		if (arr.new_arr_size == 1)
		{
			push_b(node, elem);
			break ;
		}
		max_number(elem, node, arr);
		arr.b++;
	}
}

void	push_b(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
		write(1, "pa\n", 3);
	}
}

void	rb(t_stack **data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack_size(*data) < 2)
		return ;
	tmp = *data;
	last = last_node(data);
	last->next = *data;
	*data = (*data)->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **elem)
{
	t_stack	*lastnode;
	t_stack	*firstnode;

	if ((*elem) == NULL)
		return ;
	firstnode = *elem;
	while (firstnode->next->next != NULL)
		firstnode = firstnode->next;
	lastnode = firstnode->next;
	firstnode->next = NULL;
	lastnode->next = *elem;
	*elem = lastnode;
	write(1, "rrb\n", 4);
}

void	sb(t_stack **elem)
{
	t_stack	*tmp;

	tmp = (*elem)->next;
	(*elem)->next = tmp->next;
	tmp->next = (*elem);
	(*elem) = tmp;
	write(1, "sb\n", 3);
}
