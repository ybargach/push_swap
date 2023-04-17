#include "push_swap.h"

int	stack_size(stack *elem)
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

void	push(stack **src, stack **dst)
{
	stack	*tmp;
	
	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
		write(1, "pb\n", 3);
	}
}

void	rra(stack **elem)
{
	stack	*lastnode;
	stack	*firstnode;

	if ((*elem)->next == NULL)
		return;
	firstnode = *elem;
	while (firstnode->next->next != NULL)
		firstnode = firstnode->next;
	lastnode = firstnode->next;
	firstnode->next = NULL;
	lastnode->next = *elem;
	*elem = lastnode;
	write(1, "rra\n", 4);
}

void	ra(stack **data)
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
	write(1, "ra\n", 3);
}

void	sa(stack **elem)
{
	stack	*tmp;

	tmp = (*elem)->next;
	(*elem)->next = tmp->next;
	tmp->next = (*elem);
	(*elem) = tmp;
	write(1, "sa\n", 3);
}
