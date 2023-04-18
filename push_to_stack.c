/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:56:59 by ybargach          #+#    #+#             */
/*   Updated: 2023/04/18 01:36:41 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	newnode->x = value;
	newnode->next = NULL;
	return (newnode);
}

t_stack	*last_node(t_stack **elem)
{
	t_stack	*lastnode;

	lastnode = (*elem);
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}

void	add_back(t_stack **elem, int value)
{
	t_stack	*new_node;
	t_stack	*lastnode;

	if ((*elem) == NULL)
		(*elem) = create_node(value);
	else
	{
		new_node = create_node(value);
		lastnode = last_node(elem);
		lastnode->next = new_node;
	}
}

void	add_first(t_stack **elem, int value)
{
	t_stack	*firstnode;

	firstnode = create_node(value);
	if (!firstnode)
		return ;
	firstnode->next = *elem;
	*elem = firstnode;
}

void	free_node(t_stack **elem)
{
	t_stack	*free_node;

	free_node = NULL;
	while (*elem)
	{
		free_node = *elem;
		*elem = (*elem)->next;
		free(free_node);
	}
}

// void freeList(struct node* head)
// {
//    struct node* tmp;

//    while (head != NULL)
//     {
//        tmp = head;
//        head = head->next;
//        free(tmp);
//     }

// }
