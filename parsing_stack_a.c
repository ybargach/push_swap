/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:56:12 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/18 10:43:42 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
		write(1, "pb\n", 3);
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
	write(1, "rra\n", 4);
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
	write(1, "ra\n", 3);
}

void	sa(t_stack **elem)
{
	t_stack	*tmp;

	if ((*elem) == NULL)
		return ;
	tmp = (*elem)->next;
	(*elem)->next = tmp->next;
	tmp->next = (*elem);
	(*elem) = tmp;
	write(1, "sa\n", 3);
}
