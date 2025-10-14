
#include <stdio.h>
#include <string.h>

char search(int *element, int *list, int *size){

    for(int i=0; i< *size; i++){
        if (*(list + i) == *element){
            return 1;       
        }

    }
    return 0;
}

int main(){

    int element;
    int list[5] = {1, 2, 3, 4, 5};
    int size = sizeof(list)/sizeof(*(list+ 0));
    printf("Enter element to search in the list: ");
    scanf("%d", &element);
    
    int found = search(&element, list, &size);

    if(found == 1){
        printf("Element found in the list");
    }
    else{
        printf("Element not found");
    }
    return 0;
}

