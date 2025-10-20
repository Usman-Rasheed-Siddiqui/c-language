#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Structure definition
struct Node {
    int data;
    struct Node *next;
};

// Function declarations
struct Node* createNode(int data);
struct Node* insertAtBeginning(struct Node *head, int data);
struct Node* insertAtEnd(struct Node *head, int data);
struct Node* insertAfter(struct Node *head, int data, int searchvalue);
struct Node* deleteNode(struct Node *head, int data);
struct Node* searchNode(struct Node *head, int data);
void printList(struct Node *head);
void freeList(struct Node *head);

#endif
