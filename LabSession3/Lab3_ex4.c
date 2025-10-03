
#include <stdio.h>
#include <string.h>

char search(char *element, char *list){
    int size = strlen(list);

    for(int i=0; i<size; i++){
        if (*(list + i) == *element){
            return 1;       
        }

    }

    return 0;

}

int main(){

    char element;
    char list[] = {'1', 'a', '4', 'o', '\0'};
    printf("Enter element to search in the list: ");
    scanf("%c", &element);

    int found = search(&element, list);

    if(found == 1){
        printf("Element found in the list");
    }
    else{
        printf("Element not found");
    }

    return 0;

}