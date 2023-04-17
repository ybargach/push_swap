#include "push_swap.h"

stack	*create_node(int value)
{
	stack	*newnode;

	newnode = malloc(sizeof(stack));
	newnode->x = value;
	newnode->next = NULL;
	return (newnode);
}

stack	*last_node(stack **elem)
{
	stack	*lastnode;
	
	lastnode = (*elem);
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}

void	add_back(stack **elem, int value)
{
	stack	*new_node;
	stack	*lastnode;

	if ((*elem) == NULL)
		(*elem) = create_node(value);
	else
	{
		new_node = create_node(value);
		lastnode = last_node(elem);
		lastnode->next = new_node;
    }
}

void	add_first(stack **elem, int value)
{
	stack	*firstnode;
	
	firstnode = create_node(value);
	if (!firstnode)
		return;
	firstnode->next = *elem;
	*elem =  firstnode;
}

void	free_node(stack **elem)
{
	stack	*free_node = NULL;
	stack	*node;

	node = *elem;
	while(node)
	{
		node = free_node;
		node = node->next;
		free(free_node);
	}
	*elem = NULL;
}