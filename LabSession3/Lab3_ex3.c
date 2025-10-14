
#include <stdio.h>
#include <string.h>

int main(){
    int stop = 1;
    int element[100];
    int size = 0;
    int *stopptr = &stop;

    while(stop != 0){
    
        printf("\nEnter element for array: ");
        scanf("%d", element + size);
        size += 1;
    
        printf("Do you want to stop (0 to stop): ");
        scanf("%d", stopptr);
    }

    printf("\nElements of list: [ ");
    for(int i=0; i<size; i++){
        printf("%d ", *(element + i));
    }
    printf("]");

}

