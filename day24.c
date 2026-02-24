//Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, key;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        newnode = (struct node*) malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d", &key);

    // Delete first occurrence
    struct node *current = head, *previous = NULL;

    // If key is in head
    if (current != NULL && current->data == key) {
        head = current->next;
        free(current);
    } else {
        while (current != NULL && current->data != key) {
            previous = current;
            current = current->next;
        }

        if (current != NULL) {
            previous->next = current->next;
            free(current);
        }
    }

    // Print updated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}