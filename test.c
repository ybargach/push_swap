#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* first;
    Node* last;
} Stack;

void initStack(struct Stack* stack) {
    stack->first = NULL;
    stack->last = NULL;
}

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack* stack, int val) {
    struct Node* newNode = createNode(val);
    if (stack->first == NULL) {
        stack->first = newNode;
        stack->last = newNode;
    } else {
        newNode->next = stack->first;
        stack->first = newNode;
    }
}

struct Node* pop(struct Stack* stack) {
    if (stack->first == NULL) {
        return NULL;
    }
    struct Node* temp = stack->first;
    if (stack->first == stack->last) {
        stack->last = NULL;
    }
    stack->first = stack->first->next;
    return temp;
}

struct Node* peek(struct Stack* stack) {
    return stack->first;
}

void sortStack(struct Stack* mainStack, struct Stack* tempStack) {
    struct Node* firstNode = pop(mainStack);
    push(tempStack, firstNode->val);
    while (mainStack->first != NULL) {
        struct Node* tempNode = pop(mainStack);
        while (tempStack->first != NULL) {
            if (tempNode->val < peek(tempStack)->val) {
                struct Node* poppedNode = pop(tempStack);
                push(mainStack, poppedNode->val);
            } else {
                break;
            }
        }
        push(tempStack, tempNode->val);
    }
    while (tempStack->first != NULL) {
        struct Node* currentNode = pop(tempStack);
        push(mainStack, currentNode->val);
    }
}

int main() {
    struct Stack itemStack;
    initStack(&itemStack);
    push(&itemStack, 1);
    push(&itemStack, 1);
    push(&itemStack, 3);
    struct Stack tempStack;
    initStack(&tempStack);
    sortStack(&itemStack, &tempStack);
    while (itemStack.first != NULL) {
        struct Node* currentNode = pop(&itemStack);
        printf("%d ", currentNode->val);
        free(currentNode);
    }
    return 0;
}
