
#include <stdio.h>
#include <string.h>

// void Swapping(int *a, int *b){
//     int temp;
//     temp = *a;

//     *a = *b;
//     *b = temp;
// }

// int main(){
//     int element1, element2;
//     element1 = 23;
//     element2 = 35;
//     printf("\nelement1 = %d", element1);
//     printf("\nelement2 = %d", element2);

//     Swapping(&element1, &element2);
//     printf("\nelement1 = %d", element1);
//     printf("\nelement2 = %d", element2);
// }


// void Reverse(char *arr){
//     for(int i=0, j=strlen(arr)-1; i<=j; i++, j--){
//         char ptri;
//         ptri = *(arr + i);
//         *(arr + i) = *(arr + j);
//         *(arr + j) = ptri;
//     }
// }

// int main(){
//     char arr[] = "CAR";
//     Reverse(arr);
//     for(int i=0; i<strlen(arr); i++){
//         printf("%c", *(arr + i));
//     }
// }

// int main(){
//     int elements[100];
//     int stop = 0;
//     int size = 0;
//     int *stopptr = &stop;
//     while (stop != 1){
//         printf("Enter a number for the list: ");
//         scanf("%d", (elements + size));
//         size += 1;

//         printf("Do you want to quit (1 to quit): ");
//         scanf("%d", stopptr);
//     }

//     for(int i=0; i < size; i++){
//         printf("%d ", *(elements + i));
//     }
// }

// void *Search(char *arr, char a){
//     for(int i=0; i < strlen(arr); i++){
//         if(*(arr + i) == a){
//             return (arr+i);
//         }
//     }
//     return NULL;
// }

// int main(){
//     char arr[] = "Car is in the desert";
//     char found;
//     printf("Enter element to find in the list: ");
//     scanf("%c", &found);
    
//     char *ptr;
//     ptr = Search(arr, found);
    
//     if (ptr != NULL){
//         printf("Element '%c' was found at %ld\n", found, ptr);
//     }
//     else{
//         printf("Element was not found");
//     }

//     for(int i=0; i < strlen(arr); i++){
//         printf("Element '%c' is at: %d\n", *(arr + i), (arr + i));
//     }
// }


// void MatSum(int *mat1, int *mat2, int *result, int rows, int cols){
//     for(int i=0; i<rows; i++){
//         for(int j=0; j<cols; j++ ){
//             *(result + i*cols + j) = *(mat1 + i*cols + j) + *(mat2 + i*cols + j); 
//         }
//     }
// }

// int main(){
//     int mat1[3][3] = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9},
//     };

//     int mat2[3][3] = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9},
//     };

//     int result[3][3];
//     int rows = 3, cols = 3;
//     MatSum((int *)mat1, (int *)mat2, (int *)result, rows, cols);

//     for(int i=0; i<rows; i++){
//         for(int j=0; j<cols; j++ ){
//             printf("%d ", *(*(result + i) + j));
//         }
//         printf("\n");
//     }
// }


void Entering(int *arr, int *size){
    int stop=1;

    while(stop != 0){
        printf("\nEnter Element: ");
        scanf("%d", (arr + *size));
        *size += 1;

        printf("\nQuit (0 to stop): ");
        scanf("%d", &stop);
    }
}

int main(){
    int arr[100];
    int size=0;
    Entering(arr, &size);
    printf("\nElements: ");
    for(int i=0; i<size; i++){
        printf("%d", *(arr+i));
    }
}


// #include <stdio.h>
// #include <string.h>

// char search(int *element, int *list, int *size){

//     for(int i=0; i< *size; i++){
//         if (*(list + i) == *element){
//             return 1;       
//         }

//     }
//     return 0;
// }

// int main(){

//     int element;
//     int list[5] = {1, 2, 3, 4, 5};
//     int size = sizeof(list)/sizeof(*(list+ 0));
//     printf("Enter element to search in the list: ");
//     scanf("%d", &element);
//     int found;

//     found = search(&element, list, &size);

//     if(found != 0){
//         printf("Element found in the list");
//     }
//     else{
//         printf("Element not found");
//     }
//     return 0;
// }

