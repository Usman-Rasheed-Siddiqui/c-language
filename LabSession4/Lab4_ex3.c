#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>

int *ConvertToArray(struct Node *head, int size){

    int *arr = (int *)malloc(size *sizeof(int));
    if(arr == NULL){
        fprintf(stderr, "Memory Allocation Failed");
        exit(1);
    }

    struct Node *current = head;
    int i=0;
    while(current != NULL){
        arr[i] = current->data;
        current = current->next;
        i ++;
    }
    return arr;
}

int main(){
    struct Node *head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);

    struct Node *current = head;
    int size = 0;
    while(current != NULL){
        size++;
        current = current->next;
    }

    int *arr = ConvertToArray(head, size);
    printf("Elements: [");
    for(int i=0; i <size; i++){
        printf(" %d ", arr[i]);
    }
    printf("]");
}
