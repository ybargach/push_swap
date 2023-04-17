#include "push_swap.h"

void	chunk_array(stack **elem, stack **node, data arr)
{
	int	i;
	int	j;

	i = 0;
	arr.a = 0;
	while (i < arr.arr_size)
	{
		j = i;
		arr.mid_number = i + arr.chunk_size / 2;
		while (j < (i + arr.chunk_size) && j < arr.arr_size)
			j++;
		arr.a++;
		i = i + arr.chunk_size;
	}
		check_less(elem, node, arr);
}

void	push_data_to_B(stack **a, stack **b, data arr)
{
	int	size;
	int	i;
	int	save;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		if ((*a)->x <= arr.max_number)
		{
			save = (*a)->x;
			push(a, b);
			if (save > arr.mid_number)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
}

void	check_less(stack **elem, stack **node, data arr)
{
	int	a;
	int	start;
	int	end;

	a = 1;
	start = 0;
	end = 0;
	arr.max_number = 0;
	arr.mid_number = 0;
	while (a <= arr.a)
	{
		end = arr.chunk_size * a;
		if (end > arr.arr_size)
			end = arr.arr_size;
		start = end - arr.chunk_size;
		arr.max_number = arr.number[end - 1];
		arr.mid_number = arr.number[start + (arr.chunk_size / 2)];
		push_data_to_B(elem, node, arr);
		a++;
	}
}

void	check_sorb_b(stack **elem, stack **node)
{
	if ((*elem)->next == NULL)
		push(node, elem);
	else if ((*elem)->x < (*elem)->next->x)
		sa(elem);
	push(node, elem);
}

