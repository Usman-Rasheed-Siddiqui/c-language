
#include <stdio.h>

void Swapping(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 2;
    int b = 3;
    printf("Before Swapping: ");
    printf("\na = %d \nb = %d", a, b);

    Swapping(&a, &b);
    printf("\nAfter Swapping: ");
    printf("\na = %d \nb = %d", a, b);
}



