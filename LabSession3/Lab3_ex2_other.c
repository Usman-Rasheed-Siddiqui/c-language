
#include <stdio.h>
#include <string.h>


void Reverse(char *arr){
    printf("\nReverse Order: ");
    for(int i= strlen(arr)-1; i >= 0; i-- ){
        printf("%c", *(arr + i));
    }
}

int main(){
    char arr[] = "Car";
    printf("Original Order: ");
    for(int i=0; i < strlen(arr); i++ ){
        printf("%c", *(arr + i));       }
    Reverse(arr);
}

