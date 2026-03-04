//Problem: Implement push and pop operations on a stack and verify stack operations.

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top--;
    }
}

int main()
{
    int n, m, i, value;

    // number of elements to push
    scanf("%d", &n);

    // pushing elements into stack
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(value);
    }

    // number of pop operations
    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        pop();
    }

    // display remaining stack from top to bottom
    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}