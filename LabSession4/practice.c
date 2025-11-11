
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL){
        fprintf(stderr, "Memory Allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *InsertAtBeginning(struct Node *head, int data){
    struct Node *newNode = createNode(data);
    if (head == NULL){
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

struct Node *InsertAtEnd(struct Node *head, int data){
    struct Node *newNode = createNode(data);
    if (head == NULL){
        return newNode;
    }
    struct Node *current = head;

    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node *InsertAfter(struct Node *head, int data, int value){
    struct Node *newNode = createNode(data);
    if (head == NULL){
        return newNode;
    }
    struct Node *current = head;

    while(current != NULL && current->data != value){
        current = current->next;
    }

    if (current == NULL){
        printf("Node with given value not found");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node *DeleteNode(struct Node *head, int data){
    if (head == NULL){
        return NULL;
    }

    struct Node *current = head;
    struct Node *prev = NULL;

    while(current != NULL && current->data != data){
        prev = current;
        current = current -> next;
    }

    if (current == NULL){
        printf("Node with value not found");
        return head;
    }
    
    if (prev == NULL){
        head = current ->next;
    }
    else{
        prev->next = current->next;
    }

    free(current);
    return head;

}

struct Node *searchNode(struct Node *head, int data){
    struct Node *current = head;

    while(current != NULL && current->data != data){
        current = current->next;
    }

    if (current == NULL){
        return NULL;
    }

    return current;

}

void freeNode(struct Node *head){
    struct Node *current = head;

    while (current != NULL){
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

void printList(struct Node *head){
    struct Node *current = head;

    while (current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main(){
    struct Node *head = NULL;

    printf("Insert at Beginning:\n");
    head = InsertAtBeginning(head, 10);
    head = InsertAtBeginning(head, 20);
    printList(head);

    printf("\nInsert at End:\n");
    head = InsertAtEnd(head, 30);
    head = InsertAtEnd(head, 40);
    printList(head);

    printf("\nInsert After 20:\n");
    head = InsertAfter(head, 25, 20);
    printList(head);

    printf("\nSearch 25:\n");
    struct Node *found = searchNode(head, 25);
    if(found) printf("Node Found: %d\n", found->data);
    else printf("Node Not Found\n");

    printf("\nDelete 30:\n");
    head = DeleteNode(head, 30);
    printList(head);

    printf("\nDelete Head (20):\n");
    head = DeleteNode(head, 20);
    printList(head);

    printf("\nFreeing list...\n");
    freeNode(head);
    return 0;
}