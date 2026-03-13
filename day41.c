//Problem Statement: Implement a Queue using a linked list supporting enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
int dequeue() {
    if (front == NULL)
        return -1;

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int type;
        scanf("%d", &type);

        if(type == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if(type == 2) {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}



