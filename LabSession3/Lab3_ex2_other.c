
#include <stdio.h>
#include <string.h>


void Reverse(char *arr){
    printf("Reverse Order: ");
    for(int i= strlen(arr)-1; i >= 0; i-- ){
        printf("%c", *(arr + i));
    }
}

int main(){
    char arr[] = "Car";
    Reverse(arr);
}