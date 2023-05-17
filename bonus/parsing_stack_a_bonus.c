/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack_a_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:56:12 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/17 21:10:10 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_size(t_stack *elem)
{
	int	a;

	a = 0;
	while (elem)
	{
		a++;
		elem = elem->next;
	}
	return (a);
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if ((*dst) == NULL)
		return ;
	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}

void	rra(t_stack **elem)
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

void	ra(t_stack **data)
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

void	sa(t_stack **elem)
{
	t_stack	*tmp;

	tmp = (*elem)->next;
	(*elem)->next = tmp->next;
	tmp->next = (*elem);
	(*elem) = tmp;
}