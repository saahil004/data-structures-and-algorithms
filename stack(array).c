#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s) {
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s) {
    if (s->top >= s->size - 1)
    {
        return 1;
    }
    return 0;
}

int push(int val, struct stack *s) {
    if (isFull(s)) {
        printf("Stack overflow.\n");
        return 0;
    }
    s->top++;
    s->arr[s->top] = val;
    printf("Push successful.\n");
    return 1;
}

int pop(struct stack *s) {
    if (isEmpty(s))
    {
        printf("Stack underflow.\n");
        return 0;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
    
}

int peek(struct stack *s, int i) {
    if (s->top - i + 1 < 0)
    {
        printf("Invalid position.\n");
        return -1;
    }
    return s->arr[s->top - i + 1];
}

int stackTop(struct stack *s) {
    return s->arr[s->top];
}

int stackBottom(struct stack *s) {
    return s->arr[0];

}


int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter the size of stack: ");
    scanf("%d", &s->size);
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int c = 0;
    int val;
    while (c != 7)
    {
        printf("Enter 1 to push a value into stack.\nEnter 2 to pop a value from the stack.\nEnter 3 to peek to an index.\nEnter 5 to see stack top.\nEnter 6 to see stack bottom.\nEnter 7 to exit.\nChoice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter value to be pushed to the stack: ");
            scanf("%d", &val);
            push(val, s);
            printf("Stack after push:\n");
            for (int i = s->top; i >= 0; i--)
            {
                printf("%d\n", s->arr[i]);
            }
            
            break;
        case 2:
            printf("value: %d\n", pop(s));
            printf("Stack after pop:\n");
            for (int i = s->top; i >= 0; i--)
            {
                printf("%d\n", s->arr[i]);
            }
            break;
        case 3:
            printf("Stack:\n");
            for (int i = s->top; i >= 0; i--)
            {
                printf("%d\n", s->arr[i]);
            }
            printf("Enter position in the stack to peek at: ");
            scanf("%d", &val);
            printf("value = %d\n", peek(s, val));
            break;    
        case 5:
            printf("Top: %d\n", stackTop(s));    
            break;
        case 6:
            printf("Bottom: %d\n", stackBottom(s));    
            break;
        default:
            break;
        }
    }
    
    return 0;
}