typedef struct stack {
    int x;
    struct stack* next;
} stack;
typedef struct data {
    int    *number;
    int    arr_size;
    int    chunk_size;
    int    mid_number;
} data;
# include <stdlib.h>
void pusha(stack** top_ref, int data) {
    stack* new_node = (stack*)malloc(sizeof(stack));
    new_node->x = data;
    new_node->next = *top_ref;
    *top_ref = new_node;
}
void    push(stack **stack_b, stack **stack_a)
{
    stack    *tmp;  
    if (stack_a && *stack_a)
    {
        tmp = *stack_a;
        tmp->next = *stack_b;
        if((*stack_a)->next)
            *stack_a = (*stack_a)->next;
        if(*stack_b)
            *stack_b = tmp;
    }
}
void    chunk_array(stack **elem, stack **node, data arr)
{
    int    i;
    int    j;
    i = 0;
    while (i < arr.arr_size)
    {
        j = i;
        arr.mid_number = i + arr.chunk_size / 2;
        while (j < (i + arr.chunk_size) && j < arr.arr_size)
            j++;
        //if (arr.arr_size != i + 1)
            check_less(elem, node, arr, arr.mid_number);
        i = i + arr.chunk_size;
    }
}
void    check_less(stack **elem, stack **node, data arr, int size_chunk)
{
    int    a;
    stack *newnode;
    a = 0;
    newnode = (*elem);
    while (a < arr.arr_size)
    {
        if (arr.number[size_chunk] > newnode->x)
             push(node, elem);
        if (arr.number[size_chunk] < newnode->x)
        {
            push(node, elem);
            //rra(node);
        }
        if(newnode->next != NULL)
            newnode = newnode->next;
        a++;
    }
}
// //void    put_array(stack **elem, stack **node, int index)
// {
//     int        a;
//     int        number[index];
//     stack    *newnode;
//     data    array;
//     a = 0;
//     array.number = number;
//     array.arr_size = index;
//     array.chunk_size = array.arr_size / 5;
//     newnode = (*elem);
//     while (a < index)
//     {
//         array.number[a] = newnode->x;
//         newnode = newnode->next;
//         a++;
//     }
//     //check_sort(number, index);
//     chunk_array(elem, node, array);
// }
int main() {
    stack* stack_a = NULL;
    stack* stack_b = NULL;
    pusha(&stack_a, 10);
    pusha(&stack_a, 20);
    pusha(&stack_a, 30);
    pusha(&stack_a, 40);
    pusha(&stack_a, 50);
    pusha(&stack_a, 60);

    // printf("Before:\n");
    // print_stack(stack_a);
    // print_stack(stack_b);

    put_array(&stack_a, &stack_b, 6);

    // printf("After:\n");
    // print_stack(stack_a);
    // print_stack(stack_b);

    return 0;
}

