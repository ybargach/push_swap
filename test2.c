#include "push_swap.h"
typedef struct stack {
    int x;
    struct node* next;
} stack;

void    swap(stack **elem)
{
    stack *temp = (*elem);
    (*elem) = (*elem)->next;
    (*elem)->next = temp;
}
stack    *create_new_node(int value)
{
    stack *elem = malloc(sizeof(stack));
    elem->x = value;
    elem->next = NULL;
    return (elem);
}
stack    *check_lastnode(stack *elem)
{
    stack *last_node = elem;
    while (last_node)
    {
        if (last_node->next)
          last_node = last_node->next;
        else
          break ;
    }
    return (last_node);
}
void    last_to_first(stack **elem)
{
    stack *tmp = (*elem);
    stack *last = check_lastnode(*elem);
    while (tmp)
    {
      if (tmp->next == last)
        tmp->next = NULL;
      tmp = tmp->next;
    }
    last->next = *elem
    *elem = last;
}
void    first_to_last(stack **elem)
{
    stack *last = check_lastnode(*elem);
    stack *tmp = *elem;
    tmp->next = NULL;
    *elem = *elem->next;
    last->next = *tmp;
    
}

void    listend(stack **elem, int value)
{
  stack *new_node = create_new_node(value);
  if (!*elem)
    *elem = *new_node;
  else
  {
    stack *last = check_lastnode(*elem);
    last->next = new_node; 
  }
}

void    check_sort(stack *elem)
{
    if ((*elem)->x < (*elem)->next->x)
        swapfirstsecond(elem);
}

void sort_five(node **elem)
{
    int a = 0;
    while(a < 2)
    {
      node *last_node = check_lastnode(elem);
      if ((*elem)->x > (*elem)->next->x)
        swapfirstsecond(elem);
      if ((*elem)->x > last_node->x)
        last_to_first(elem);
      push_b(elem, (*elem)->x);
      deletelement(elem, (*elem)->x);
    a++;
  }
  //sort_three(elem);
}
void testa(node **elem, node **node)
{
 int a = 0;
  while(a < 2)
  {
    check_sort_b(elem, node);
    node *last = check_lastnode(elem);
    if ((*elem)->next->x > last->x)
      last_to_first(elem);
    a++;
  }
}
int main()
{
push(&test, 1); 
push(&test, 13);
push(&test, 15);
push(&test, 19);
push(&test, 0);
sort_five(&test.A);
testa(&test.A, &test.B);

}