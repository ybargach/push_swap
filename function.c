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
//newnode
stack	*create_node(int value)
{
	stack	*newnode;

	newnode = malloc(sizeof(stack));
	newnode->x = value;
	newnode->next = NULL;
	return (newnode);
}
//lastnode;
stack	*last_node(stack **elem)
{
	stack	*lastnode;
	
	lastnode = (*elem);
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}
//swap
void	sa(stack **elem)
{
	stack	*tmp;

	tmp = (*elem)->next;
	(*elem)->next = tmp->next;
	tmp->next = (*elem);
	(*elem) = tmp;
}
// bottom to top
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
}
// top to bottom
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
}
//add_back
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
//add_first
void	add_first(stack **elem, int value)
{
	stack	*firstnode;
	
	firstnode = create_node(value);
	if (!firstnode)
		return;
	firstnode->next = *elem;
	*elem =  firstnode;
}
//free_one_node
void	ft_free(stack **elem, int value)
{
	stack	*free_node;

	if ((*elem)->x == value)
	{
		free_node = *elem;
		*elem = (*elem)->next;
		free (free_node);
	}
}
//free_all_node
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
//push A to B
void	push(stack **src, stack **dst)
{
	stack	*tmp;
	
	if (*src)
	{
		printf("pb\n");
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}
//chunk array
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
//push_data
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
			{
				rb(b);
				//printf("rb\n");
			}
		}
		else
		{
			ra(a);
			printf("ra\n");
		}
		i++;
	}
}
//check high or less
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
//stack to array
void	put_array(stack **elem, stack **node, int index)
{
	int		a;
	int		number[index];
	stack	*newnode;
	stack	*tmp;
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
	push_A_to_B(elem, node, array);
}
//sort_three
void	sort_three(stack **elem)
{
	stack	*lastnode;

	lastnode = last_node(elem);
	if ((*elem)->x > (*elem)->next->x)
	{
		sa(elem);
		printf("sa\n");
	}
	if ((*elem)->next->x > lastnode->x)
	{
		rra(elem);
		printf("rra\n");
	}
	if ((*elem)->x > (*elem)->next->x)
	{
		sa(elem);
		printf("sa\n");
	}
}
//check_sort_b
void	check_sorb_b(stack **elem, stack **node)
{
	if ((*elem)->next == NULL)
		push(node, elem);
	else if ((*elem)->x < (*elem)->next->x)
		sa(elem);
	push(node, elem);
}
//sort_five
void	sort_fives(stack **elem, stack **node)
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
void  check(stack **elem)
{
    stack    *lastnode;

    lastnode = last_node(elem);
    if ((*elem)->x > (*elem)->next->x)
        sa(elem);
    if ((*elem)->next->x > lastnode->x)
        rra(elem);
    if ((*elem)->x > (*elem)->next->x)
        sa(elem);
}
void    sort_five(stack **elem, stack **node)
{
  stack *newelem;
  newelem = *elem;
  stack *lastnode;
  lastnode = last_node(elem);
    while (newelem->next != NULL)
    {
        if ((*elem)->x > (*elem)->next->x)
        {
			lastnode = last_node(elem);
			sa(elem);
			push(node, elem);
        }
		if ((*elem)->x < lastnode->x)
        {
          lastnode = last_node(elem);
          rra(elem);
          push(node, elem);
        }
        newelem = newelem->next;
    }
sort_three(elem);
//     int a = 0;
//     while (a < 2)
//     {
//         check_sorb_b(node, elem);
//         check(elem);
//             a++;
//     }
}

