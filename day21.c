//Problem: Create and Traverse Singly Linked List


#include <stdio.h>
#include <stdlib.h>

// Define structure for Node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of elements
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        // Input data
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            // First node
            head = newNode;
        } else {
            // Link new node to previous node
            temp->next = newNode;
        }

        temp = newNode;
    }

    // Traverse and print the linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}