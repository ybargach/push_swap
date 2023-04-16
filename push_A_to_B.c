#include "push_swap.h"

void	push_A_to_B(stack **elem, stack **node, data arr)
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
		max_number(elem, node, arr);
		arr.b++;
	}
}

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
		if (arr.new_arr_size == 1)
		{
			push_b(node, elem);
			break;
		}
		else if (arr.newnode->x > arr.high_number1)
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
	higher_lower(elem, node, arr);
}
//one in higher, other in lower
void	higher_lower(stack **a, stack **b, data arr)
{
	if (arr.index_1 <= (arr.new_arr_size/2) && arr.index_2 <= (arr.new_arr_size/2))
		lower_half(a, b, arr);
	else if (arr.index_1 >= (arr.new_arr_size/2) && arr.index_2 >= (arr.new_arr_size/2))
		higher_half(a, b, arr);
	else if (arr.index_1 > (arr.new_arr_size/2) && arr.index_2 <= (arr.new_arr_size/2))
		top_number_in_high(a, b, arr);
	else if (arr.index_1 <= (arr.new_arr_size/2) && arr.index_2 > (arr.new_arr_size/2))
		top_number_in_lowe(a, b, arr);
}
//top_number_in_lower
void	top_number_in_lowe(stack **a, stack **b, data arr)
{
	if (arr.index_1 < (arr.new_arr_size - arr.index_2))
	{
		arr.a = 0;
		while (arr.a < arr.index_1)
			(rb(b), arr.a++);
			//printf("1.1\n");
		push_b(b, a);
	}
	else if (arr.index_1 > (arr.new_arr_size - arr.index_2))
	{
		arr.a = 0;
		arr.b = 0;
		while (arr.a < (arr.new_arr_size - arr.index_2))
			(rrb(b), arr.b++, arr.a++);
			//printf("1.2\n");
		push_b(b, a);
		arr.a = 0;
		while (arr.a < (arr.index_1 + arr.b - 1))
			(rb(b), arr.a++);
			//printf("1.3\n");
		push_b(b, a);
		sb(a);
	}
	else if (arr.index_1 == (arr.new_arr_size - arr.index_2))
	{
		arr.a = 0;
		arr.b = 0;
		while (arr.a < arr.index_1)
			(rb(b), arr.b++, arr.a++);
			//printf("1.4\n");
		push_b(b, a);
	}
}
//top_number_in_higher
void	top_number_in_high(stack **a, stack **b, data arr)
{
	if ((arr.new_arr_size - arr.index_1) < arr.index_2)
	{
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - arr.index_1))
			(rrb(b), arr.a++);
			//printf("2.1\n");
		push_b(b, a);
	}
	else if ((arr.new_arr_size - arr.index_1) > arr.index_2)
	{
		arr.a = 0;
		arr.b = 0;
		while (arr.a < arr.index_2)
			(rb(b), arr.b++, arr.a++);
			//printf("2.2\n");
		push_b(b, a);
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - arr.index_1 + arr.b))
			(rrb(b), arr.a++);
			//printf("2.3\n");
		push_b(b, a);
		sb(a);
	}
	else if (arr.index_2 == (arr.new_arr_size - arr.index_1))
	{
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - arr.index_1))
			(rrb(b), arr.a++);
			//printf("2.4\n");
		push_b(b, a);
	}
}
//higher_half
void	higher_half(stack **a, stack **b, data arr)
{
	if (arr.index_1 > arr.index_2)
	{
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - arr.index_1))
			(rrb(b), arr.a++);
			//printf("3.1\n");
		push_b(b, a);
	}
	else if (arr.index_1 < arr.index_2)
	{
		arr.a = 0;
		arr.b = 0;
		while (arr.a < (arr.new_arr_size - arr.index_2))
			(rrb(b), arr.b++, arr.a++);
			//printf("3.2\n");
		push_b(b, a);
		arr.a = 0;
		while (arr.a < (arr.new_arr_size - (arr.index_1 + arr.b)))
			(rrb(b), arr.a++);
			//printf("3.3\n");
		push_b(b, a);
		sb(a);
	}
}
//lower_half
void	lower_half(stack **a, stack **b, data arr)
{
	if (arr.index_1 > arr.index_2)
	{
		arr.b = 0;
		arr.a = 0;
		while (arr.a < arr.index_2)
			(rb(b), arr.b++, arr.a++);
			//printf("4.1\n");
		push_b(b, a);
		while (arr.a < (arr.index_1 - 1))
			(rb(b), arr.a++);
			//printf("4.2\n");
		push_b(b, a);
		sb(a);
	}
	else if (arr.index_1 < arr.index_2)
	{
		arr.a = 0;
		while (arr.a < arr.index_1)
			(rb(b), arr.a++);
			//printf("4.3\n");
		push_b(b, a);
	}
}
void	push_b(stack **src, stack **dst)
{
	stack	*tmp;
	
	if (*src)
	{
		printf("pa\n");
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
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
	printf("rb\n");
}
void	rrb(stack **elem)
{
	stack	*lastnode;
	stack	*firstnode;

	if ((*elem)->next == NULL)
		return ;
	printf("rrb\n");
	firstnode = *elem;
	while (firstnode->next->next != NULL)
		firstnode = firstnode->next;
	lastnode = firstnode->next;
	firstnode->next = NULL;
	lastnode->next = *elem;
	*elem = lastnode;
}
void	sb(stack **elem)
{
	stack	*tmp;
	printf("sa\n");
	tmp = (*elem)->next;
	(*elem)->next = tmp->next;
	tmp->next = (*elem);
	(*elem) = tmp;
}
