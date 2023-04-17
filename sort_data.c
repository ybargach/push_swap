#include "push_swap.h"

void	sort_three(stack **elem)
{
	stack	*lastnode;

	lastnode = last_node(elem);
	if ((*elem)->x > (*elem)->next->x)
		sa(elem);
	if ((*elem)->next->x > lastnode->x)
		rra(elem);
	if ((*elem)->x > (*elem)->next->x)
		sa(elem);
}

void	sort_five(stack **elem, stack **node)
{
	int	a;

	a = 0;
	while (a < 2)
	{
		stack *lastnode;

		lastnode = last_node(elem);
		if ((*elem)->x < (*elem)->next->x)
		{
			sa(elem);
			push(node, elem);
		}
		if ((*elem)->x < lastnode->x)
		{
			rra(elem);
			push(node, elem);
		}
		a++;
	}
	sort_three(elem);
	a = 0;
	while (a < 2)
	{
		stack *lastnode;

		check_sorb_b(node, elem);
		lastnode = last_node(elem);
		if ((*elem)->next->x < lastnode->x)
			rra(elem);
		a++;
	}
}

void	sort_one_hundred(stack **elem, stack **node, int index)
{
	int		a;
	int		number[index];
	stack	*newnode;
	data	array;

	a = 0;
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
	check_sort(number, index);
	chunk_array(elem, node, array);
	push_B_to_A(elem, node, array);
}

void	sort_five_hundred(stack **elem, stack **node, int index)
{
	int		a;
	int		number[index];
	stack	*newnode;
	data	array;

	a = 0;
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
	check_sort(number, index);
	chunk_array(elem, node, array);
	push_B_to_A(elem, node, array);
}