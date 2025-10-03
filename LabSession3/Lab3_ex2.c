
#include <stdio.h>
#include <string.h>

void Reverse(char *arr){
    int i, j;
    char temp;
    int size = strlen(arr);
    
    for( i=0, j=size-1; i <= j; i++, j--){
        temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
    }
}

int main(){
    char string[100];
    printf("Enter String: ");
    scanf("%99s", string);

    Reverse(string);

    printf("Reversed String: ");
    for(int i=0; i < strlen(string); i++){
        printf("%c", *(string + i));
    }

    return 0;
}