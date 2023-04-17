#include "push_swap.h"

void	max_number(stack **elem, stack **node, data arr)
{
	arr.newnode = *node;
	arr.high_number1 = -2147483649;
	arr.high_number2 = -2147483649;
	arr.index_1 = -1;
	arr.index_2 = -1;
	arr.move = 0;
	while (arr.newnode)
	{
		if (arr.newnode->x > arr.high_number1)
		{
			arr.index_2 = arr.index_1;
			arr.index_1 = arr.move;
			arr.high_number2 = arr.high_number1;
			arr.high_number1 = arr.newnode->x;
		}
		else if (arr.newnode->x > arr.high_number2)
		{
			arr.high_number2 = arr.newnode->x;
			arr.index_2 = arr.move;
		}
		arr.move++;
		arr.newnode = arr.newnode->next;
	}
	check_higher_lower(elem, node, arr);
}

void	check_higher_lower(stack **a, stack **b, data arr)
{
	if (arr.index_1 <= (arr.new_arr_size/2) && arr.index_2 <= (arr.new_arr_size/2))
		lower_half(a, b, arr);
	else if (arr.index_1 >= (arr.new_arr_size/2) && arr.index_2 >= (arr.new_arr_size/2))
		higher_half(a, b, arr);
	else if (arr.index_1 >= (arr.new_arr_size/2) && arr.index_2 <= (arr.new_arr_size/2))
		top_number_in_higher(a, b, arr);
	else if (arr.index_1 <= (arr.new_arr_size/2) && arr.index_2 >= (arr.new_arr_size/2))
		top_number_in_lower(a, b, arr);
}

void	top_number_in_lower(stack **a, stack **b, data arr)
{
	arr.a = 0;
	arr.b = 0;
	if (arr.index_1 < (arr.new_arr_size - arr.index_2))
	{
		while (arr.a < arr.index_1)
			(rb(b), arr.a++);
		push_b(b, a);
	}
	else if (arr.index_1 > (arr.new_arr_size - arr.index_2))
	{
		while (arr.a < (arr.new_arr_size - arr.index_2))
			(rrb(b), arr.b++, arr.a++);
		push_b(b, a);
		arr.a = 0;
		while (arr.a < (arr.index_1 + arr.b - 1))
			(rb(b), arr.a++);
		push_b(b, a);
		sa(a);
	}
	else if (arr.index_1 == (arr.new_arr_size - arr.index_2))
	{
		while (arr.a < arr.index_1)
			(rb(b), arr.b++, arr.a++);
		push_b(b, a);
	}
}

void	top_number_in_higher(stack **a, stack **b, data arr)
{
	arr.a = 0;
	arr.b = 0;
	if ((arr.new_arr_size - arr.index_1) < arr.index_2)
	{
		while (arr.a < (arr.new_arr_size - arr.index_1))
			(rrb(b), arr.a++);
		push_b(b, a);
	}
	else if ((arr.new_arr_size - arr.index_1) > arr.index_2)
	{
		while (arr.a < arr.index_2)
			(rb(b), arr.b++, arr.a++);
		push_b(b, a);
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - arr.index_1 + arr.b))
			(rrb(b), arr.a++);
		push_b(b, a);
		sa(a);
	}
	else if (arr.index_2 == (arr.new_arr_size - arr.index_1))
	{
		while (arr.a < (arr.new_arr_size - arr.index_1))
			(rrb(b), arr.a++);
		push_b(b, a);
	}
}

void	higher_half(stack **a, stack **b, data arr)
{
	arr.a = 0;
	arr.b = 0;
	if (arr.index_1 > arr.index_2)
	{
		while (arr.a < (arr.new_arr_size - arr.index_1))
			(rrb(b), arr.a++);
		push_b(b, a);
	}
	else if (arr.index_1 < arr.index_2)
	{
		while (arr.a < (arr.new_arr_size - arr.index_2))
			(rrb(b), arr.b++, arr.a++);
		push_b(b, a);
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - (arr.index_1 + arr.b)))
			(rrb(b), arr.a++);
		push_b(b, a);
		sa(a);
	}
}

void	lower_half(stack **a, stack **b, data arr)
{
	arr.a = 0;
	arr.b = 0;
	if (arr.index_1 > arr.index_2)
	{
		while (arr.a < arr.index_2)
			(rb(b), arr.b++, arr.a++);
		push_b(b, a);
		while (arr.a < (arr.index_1 - 1))
			(rb(b), arr.a++);
		push_b(b, a);
		sa(a);
	}
	else if (arr.index_1 < arr.index_2)
	{
		while (arr.a < arr.index_1)
			(rb(b), arr.a++);
		push_b(b, a);
	}
}
