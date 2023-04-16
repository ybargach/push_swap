#include <stdlib.h>
typedef struct stack {
    int x;
    struct stack* next;
} stack;
stack    *create_node(int value)
{
    stack    *newnode;

    newnode = malloc(sizeof(stack));
    newnode->x = value;
    newnode->next = NULL;
    return (newnode);
}
stack    *last_node(stack **elem)
{
    stack    *lastnode;

    lastnode = (*elem);
    while (lastnode->next != NULL)
        lastnode = lastnode->next;
    return (lastnode);
}
void sa(stack **elem)
{
    stack *tmp;

    tmp = (*elem)->next;
    (*elem)->next = tmp->next;
    tmp->next = (*elem);
    (*elem) = tmp;
}
void    rra(stack **elem)
{
    stack    *lastnode;
    stack    *firstnode;

    firstnode = *elem;
    while (firstnode->next->next != NULL)
        firstnode = firstnode->next;
    lastnode = firstnode->next;
    firstnode->next = NULL;
    lastnode->next = *elem;
    *elem = lastnode;
}
void    add_back(stack **elem, int value)
{
    stack    *new_node;
    stack    *lastnode;

    if ((*elem) == NULL)
        (*elem) = create_node(value);
    else
    {
        new_node = create_node(value);
        lastnode = last_node(elem);
        lastnode->next = new_node;
    }
}
void    push(stack **dst, stack **src)
{
    stack    *tmp;

    if (src && *src)
    {
        tmp = *src;
        *src = (*src)->next;
        tmp->next = *dst;
        *dst = tmp;
    }
}
void    sort_three(stack **elem)
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
void    check_sorb_b(stack **elem, stack **node)
{
    if ((*elem)->next == NULL)
      push(node, elem);
    else if ((*elem)->x < (*elem)->next->x)
        sa(elem);
    push(node, elem);
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
    while (newelem->next != NULL)
    {
      newelem = *elem;
        stack *lastnode;

        if ((*elem)->x > (*elem)->next->x)
        {
          lastnode = last_node(elem);
            sa(elem);
            push(node, elem);
        }
        if ((*elem)->x > lastnode->x)
        {
          lastnode = last_node(elem);
          rra(elem);
          push(node, elem);
        }
        newelem = newelem->next;
    }
    sort_three(elem);
       int a = 0;
    while (a < 2)
    {
        check_sorb_b(node, elem);
        check(elem);
            a++;
    }
}
int main()
{
  stack *test = NULL;
  stack *b = NULL;
  add_back(&test, 15); 
  add_back(&test, 3);
  add_back(&test, 10);
  add_back(&test, 9);
  sort_five(&test, &b);
}