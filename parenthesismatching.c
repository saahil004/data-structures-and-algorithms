#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    char *arr;
    int size;
};

int push(struct stack *s, char p)
{
    if (s->top >= s->size - 1)
    {
        return -1;
    }
    s->top++;
    s->arr[s->top] = p;
    return 1;
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        return -1;
    }
    char val = s->arr[s->top];
    s->top--;
    return val;
}

int stackEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return -1;
}

int parenthesisMatching(char *expression)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(expression);
    s->arr = (char *)malloc(s->size * sizeof(char));
    s->top = -1;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            push(s, expression[i]);
        }
        if (expression[i] == ')')
        {
            if (pop(s) == -1)
            {
                printf("Parenthesis not balanced as a stack underflow occurred.\n");
                free(s->arr);
                free(s);
                return 0;
            }
        }
    }
    if (stackEmpty(s) == -1)
    {
        free(s->arr);
        free(s);
        printf("Parenthesis not balanced as stack is still not empty.\n");
        return 0;
    }
    printf("Balanced.\n");
    free(s->arr);
    free(s);
    return 1;
}

char oppositeParenthesis(char p)
{
    switch (p)
    {
    case '(':
        return ')';
        break;
    case '[':
        return ']';
        break;
    case '{':
        return '}';
        break;

    default:
        break;
    }
}

int multipleParenthesisMatching(char *expression)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(expression);
    s->arr = (char *)malloc(s->size * sizeof(char));
    s->top = -1;
    int ans;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(s, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            ans = pop(s);
            if (expression[i] != oppositeParenthesis(ans) || ans == -1)
            {
                printf("Parenthesis not balanced.\n");
                free(s->arr);
                free(s);
                return 0;
            }
        }
    }
    if (stackEmpty(s) == 1)
    {
        printf("Balanced.\n");
        return 1;
    }
    printf("Not balanced.\n");
    return 0;
}

int main()
{
    char expression[30];
    int c = 0;
    while (c != 3)
    {
        printf("Enter 1 to check single parenthesis.\nEnter 2 to check multiple parenthesis.\nEnter 3 to exit.\nChoice: ");
        scanf("%d", &c);
        printf("Enter expression to be checked for balanced parenthesis: ");
        scanf("%s", expression);
        switch (c)
        {
        case 1:
            parenthesisMatching(expression);
            break;
        case 2:
            multipleParenthesisMatching(expression);
            break;

        default:
            break;
        }
    }

    return 0;
}