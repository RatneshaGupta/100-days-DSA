//Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Rotate list to right by k places
struct Node* rotateRight(struct Node* head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int count = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Connect last node to head (make circular)
    temp->next = head;

    k = k % count;
    int steps = count - k;

    // Move to (n-k)th node
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Set new head
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, value, k;

    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}