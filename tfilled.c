#include "push_swap.h"

void	create_stack(stack *data)
{
	data->A = NULL;
	data->B = NULL;
}

void	ft_free(node **elem)
{
	node *free_node = *elem;
	while (free_node != NULL)
	{
		node *before_node = free_node;
		free_node = free_node->next;
		free(before_node);
	}
	*elem = NULL;
}

void	listbeg(node **elem, int value)
{
	node *new_node = create_new_node(value);
	if (!new_node)
		return;
	new_node->next = *elem;
	*elem = new_node;
}


void	swapfirstsecond(node **elem)
{
	if (elem == NULL || (*elem)->next == NULL)
		return;
	int temp = (*elem)->x;
	(*elem)->x = (*elem)->next->x;
	(*elem)->next->x = temp;
}
/////////////////

void	last_to_first(node **elem)
{
	if (elem == NULL || (*elem)->next == NULL)
		return;
	node *first_node = *elem;
	while (first_node->next->next != NULL)
		first_node = first_node->next;
	node *last_node = first_node->next;
	first_node->next = NULL;
	last_node->next = *elem;
	*elem = last_node;
}
//////////////////
 
void	first_to_last(node **elem)
{
	if (elem == NULL || (*elem)->next == NULL)
		return;
	node *last_node = *elem;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = *elem;
	*elem = (*elem)->next;
	last_node->next->next = NULL;
}

void	deletelement(node **elem, int value)
{
	node *remove;
	if ((*elem)->x == value)
	{
		remove = *elem;
		*elem = (*elem)->next;
		free (remove);
	}
}

node	*create_new_node(int value)
{
	node *elem = malloc(sizeof(node));
	elem->x = value;
	elem->next = NULL;
	return (elem);
}

void	listend(node **elem, int value)
{
	node *new_node = create_new_node(value);
	if (!new_node)
		return;
	node *curr = *elem;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	push(stack *stack, int value)
{
	if (stack->A == NULL)
	{
		node *newnode = create_new_node(value);
		stack->A = newnode;
	}
	else
		listend(&stack->A, value);
}

void	push_b(stack *stack, int value)
{
	if (stack->B == NULL)
	{
		node *newnode = create_new_node(value);
		stack->B = newnode;
	}
	else
		listbeg(&stack->B, value);
}

void	check_sort_b(node **elem)
{
	if ((*elem)->x < (*elem)->next->x)
		swapfirstsecond(elem);
	push(elem, (*elem)->x);
	deletelement(elem, (*elem)->x);
}

node	*check_lastnode(node **elem)
{
	node *last_node = *elem;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

void	sort_three(node **elem)
{
	node *last = check_lastnode(elem);
	if ((*elem)->x > (*elem)->next->x)
		swapfirstsecond(elem);
	if ((*elem)->next->x > last->x)
		last_to_first(elem);
	if ((*elem)->x > (*elem)->next->x)
		swapfirstsecond(elem);
}

void	sort_five(node **elem)
{
	int a = 0;
	while(a < 2)
	{
		node *last_node = check_lastnode(elem);
		if ((*elem)->x < (*elem)->next->x)
			swapfirstsecond(elem);
		if ((*elem)->x < last_node->x)
			last_to_first(elem);
		push_b(elem, (*elem)->x);
		deletelement(elem, (*elem)->x);
		a++;
	}
	sort_three(elem);
	a = 0;
	while(a < 2)
	{
		check_sort_b(elem);
		node *last = check_lastnode(elem);
		if ((*elem)->next->x > last->x)
			last_to_first(elem);
		a++;
	}
}

// void	check_node(stack *stack)
// {
// 	node *temp = stack->A->next->x;
// 	stack->A->x;
// 	if (stack->A->x < temp)
// 		//first_to_last(elem);
// 	printf("aaaaaaa %d\n", temp);
// 	//printf("bbbbbbb %d\n", (*elem)->x);
// }

// int main()
// {
// 	stack test;
//   create_stack(&test);
//   push(&test, 1); 
//   push(&test, 15);
//   push(&test, 19);
//   push(&test, 13);
//   push(&test, 0);
//   //
// 	node *root = malloc(sizeof(node));
// 	root->x = 15;
// 	root->next = NULL;
// 	listend(&root, -4);
// 	listend(&root, 97);
// 	listend(&root, 21);
// 	node *curr = root;
// 	while (curr != NULL)
// 	{
// 		printf("%d\n", curr->x);
// 		curr = curr->next;
// 	}
// 	ft_free(&root);
// }