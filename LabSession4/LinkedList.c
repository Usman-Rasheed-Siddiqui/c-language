
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


struct Node *createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL){
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertAtBeginning(struct Node *head, int data){
    struct Node *newNode = createNode(data);
    if (head == NULL){
        return newNode;
    }
    newNode->next = head;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *newNode = createNode(data);
    if (head == NULL){
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node *insertAfter(struct Node *head, int data, int searchvalue){
    struct Node *newNode = createNode(data);
    struct Node *current = head;
    while (current != NULL && current->data != searchvalue){
        current = current->next;
    }

    if (current == NULL){
        printf("Node with search value not found\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node *deleteNode(struct Node *head, int data){

    struct Node *current = head;
    struct Node *prev = NULL;

    while( current != NULL && current->data != data){
        prev = current;
        current = current->next;
    }

    if (current == NULL){
        printf("Node with value not found\n");
        return head;
    }

    if (prev == NULL){
        head = current -> next;
    }
    else {
        prev->next = current->next;
    }
    free(current);
    return head;
}

struct Node *searchNode(struct Node *head, int data){
    struct Node *current = head;

    while(current != NULL){
        if(current->data == data){
            return current;
        }
        current = current->next;
    }
    return NULL;
}   

void printList(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head){
    struct Node *current = head;
    while (current != NULL){
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

// int main() {
//     struct Node* head = NULL;

//     // Insert at beginning
//     head = insertAtBeginning(3, head);
//     head = insertAtBeginning(2, head);
//     head = insertAtBeginning(1, head);

//     // Insert at end
//     head = insertAtEnd(4, head);
//     head = insertAtEnd(5, head);

//     // Insert after specific value
//     head = insertAfter(head, 6, 3);

//     printf("Linked List: ");
//     printList(head);

//     // Search
//     int searchValue = 4;
//     struct Node* found = searchNode(searchValue, head);
//     if (found)
//         printf("Node with value %d found!\n", searchValue);
//     else
//         printf("Node with value %d not found!\n", searchValue);

//     // Delete
//     int deleteValue = 2;
//     head = deleteNode(head, deleteValue);

//     printf("After deleting %d: ", deleteValue);
//     printList(head);

//     // Free memory
//     freeList(head);
//     return 0;
// }

