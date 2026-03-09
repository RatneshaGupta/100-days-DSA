//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

// Dequeue operation
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display()
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    int n, m, x;

    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    // Number of dequeue operations
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}