
#include <stdio.h>
#include "LinkedList.h"


struct Node *MergeLL(struct Node *head1, struct Node *head2){
    
    struct Node *current1 = head1;
    struct Node *current2 = head2;

    if(current1 == NULL){
        return current2;
    }
    
    if(current2 == NULL){
        return current1;
    }

    while(current1->next !=NULL){
        current1 = current1->next;
    }
    
    current1->next = head2;

    return head1;
}


int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *merged = NULL;

    head1 = insertAtEnd(head1, 1);
    head1 = insertAtEnd(head1, 2);
    head1 = insertAtEnd(head1, 3);

    head2 = insertAtEnd(head2, 4);
    head2 = insertAtEnd(head2, 5);
    head2 = insertAtEnd(head2, 6);

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    merged = MergeLL(head1, head2);

    printf("Merged List: ");
    printList(merged);

    freeList(merged);
    return 0;
}