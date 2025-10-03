
#include <stdio.h>

int *Swapping(int *arr){
    int a;

    a = arr[0];
    arr[0] = arr[1];
    arr[1] = a;

    return arr;
}

int main() {

    int array[] = {2, 3};
    int *ptr;
    
    printf("Intial Array Elements:\n");
    for (int i=0; i<2; i++){
        printf("Position %d: %d\n", i, array[i]);
    }

    ptr = Swapping(&array[0]);


    printf("Swapped Array Elements:\n ");
    for (int i=0; i<2; i++){
        printf("Position %d: %d\n", i, ptr[i]);
    }
    
    return 0;
}
