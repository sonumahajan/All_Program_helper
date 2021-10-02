#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node {
    int value;
    struct node* next;
};

// prints linked list value
void printLinkedlist(struct node* p) {
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
}

int main() {
    // Initialize nodes
    struct node* head;
    struct node* one = NULL;
    struct node* two = NULL;
    struct node* three = NULL;
    struct node* four = NULL;
    struct node* five = NULL;

    // Allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    four = malloc(sizeof(struct node));
    five = malloc(sizeof(struct node));

    // Assigning value
    one->value = 1;
    two->value = 2;
    three->value = 3;
    four->value = 4;
    five->value = 5;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;

    // printing node-value
    head = one;
    printLinkedlist(head);
}