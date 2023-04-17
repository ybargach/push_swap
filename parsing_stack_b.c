#include "push_swap.h"

void	push_B_to_A(stack **elem, stack **node, data arr)
{
	stack *newnode;
	
	newnode = *node;
	arr.arr_size = stack_size(newnode);
	arr.b = 0;
	while (arr.b < arr.arr_size)
	{
	 	if (node == NULL)
	 		break;
		arr.new_arr_size = stack_size(*node);
		if (arr.new_arr_size == 1)
		{
			push_b(node, elem);
			break;
		}
		max_number(elem, node, arr);
		arr.b++;
	}
}

void	push_b(stack **src, stack **dst)
{
	stack	*tmp;
	
	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
		write(1, "pa\n", 3);
	}
}

void	rb(stack **data)
{
	stack	*tmp;
	stack	*last;

	if (stack_size(*data) < 2)
		return ;
	tmp = *data;
	last = last_node(data);
	last->next = *data;
	*data = (*data)->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(stack **elem)
{
	stack	*lastnode;
	stack	*firstnode;

	if ((*elem)->next == NULL)
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

void	sb(stack **elem)
{
	stack	*tmp;

	tmp = (*elem)->next;
	(*elem)->next = tmp->next;
	tmp->next = (*elem);
	(*elem) = tmp;
	write(1, "sb\n", 3);
}
