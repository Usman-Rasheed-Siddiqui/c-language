
#include <stdio.h>


void Reverse(char *arr, int size) {
    
    for(int i = 0 , j = size - 1; i <= j; i++ , j--) {
        char temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
    }

}

int main(){
    char word[] = "Car";
    int size = sizeof(word)/sizeof(word[0]);

    printf("Original Order: ");
    for (int i=0; i<size; i++){
        printf("%c", *(word + i));
    }


    Reverse(word, size);

    printf("\nReverse Order: ");
    for (int i=0; i<size; i++){
        printf("%c", *(word + i));
    }
    
    return 0;
}
