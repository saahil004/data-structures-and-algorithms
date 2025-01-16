#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct stack
{
    struct Node *top;
    int size;
};

void displayStack(struct stack *s) {
    struct Node *ptr = s->top;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }   
}

void push(int val, struct stack *s) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("Stack overflowed.\n");
        return;
    }
    new->data = val;
    new->next = s->top;
    s->top = new;
    printf("Pushed successfully.\n");
    s->size++;
    // return new;
}

int pop(struct stack *s) {
    if (s->top == NULL)
    {
        printf("Stack underflow.\n");
        return -1;
    }
    struct Node *ptr = s->top;
    int val = s->top->data;
    s->top = s->top->next;
    free(ptr);
    printf("Popped successfully.\n");
    s->size--;
    return val;
}

int peek(int i, struct stack *s) {
    if (i > s->size) {
        printf("Cant peek.\n");
        return -1;
    }
    struct Node *ptr = s->top;
    for (int j = 1; j <= i-1; j++)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int stackTop(struct stack *s) {
    return s->top->data;
}

int stackBottom(struct stack *s) {
    struct Node *ptr = s->top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 0;
    s->top = NULL;
    int c = 0;
    int val;
    while (c != 6)
    {
        printf("Enter 1 to show stack.\nEnter 2 to push a value.\nEnter 3 to pop a value.\nEnter 4 to peek at an index.\nEnter 5 to see stack top and bottom.\nEnter 6 to exit.\nChoice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            displayStack(s);
            break;
        case 2:
            printf("Enter value to be pushed: ");
            scanf("%d", &val);
            push(val, s);
            
            break;
        case 3:
            pop(s);
            break;
        case 4:
            printf("Enter position to be peeked: ");
            scanf("%d", &val);
            printf("Peek value: %d\n", peek(val, s));
            break;
        case 5:
            printf("Stack top: %d\nStack bottom: %d\n", stackTop(s), stackBottom(s));
            break;    
        default:
            break;
        }
    }
    
    return 0;
}