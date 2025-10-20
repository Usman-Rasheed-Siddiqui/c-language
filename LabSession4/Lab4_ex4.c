
#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>

struct Node *RemoveOddIndices(struct Node *head){

    int i=1;
    struct Node *prev = head;
    struct Node *current = head->next;
    while(current != NULL){
        if(i % 2 != 0){
            prev->next = current->next;
            free(current);
            current = current->next;
        }
        else{
            prev = current;
            current = current->next;
        }
        i++;
    }
    
    return head;
}

int main(){
    struct Node *head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtBeginning(head, 6);
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 4);

    printf("Original list:\n");
    printList(head);

    head = RemoveOddIndices(head);
    printf("\nList after removing odd indices:\n");
    printList(head);

    return 0;
}
