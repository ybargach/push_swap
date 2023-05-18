/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack_b_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:56:30 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/18 10:37:52 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_b(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
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
}

void	sb(t_stack **elem)
{
	t_stack	*tmp;

	if ((*elem) == NULL)
		return ;
	tmp = (*elem)->next;
	(*elem)->next = tmp->next;
	tmp->next = (*elem);
	(*elem) = tmp;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
