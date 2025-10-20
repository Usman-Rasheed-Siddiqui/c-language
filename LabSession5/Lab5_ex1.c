
#include <stdio.h>
#include <string.h>

int main(){
    FILE *fptr;
    fptr = fopen("Lab5.txt", "w");
    if(fptr != NULL){
        fprintf(fptr, "This is a test sentence written to a file using C programming.");
    }
    else{
        printf("Unable to open the file");
    }
    fclose(fptr);

    fptr = fopen("Lab5.txt", "a");
    if(fptr != NULL){
        fprintf(fptr, "\nThis line was added later to demonstrate file appending in C.");
    }
    else{
        printf("Unable to open the file");
    }
    fclose(fptr);

    fptr = fopen("Lab5.txt", "r");
    if(fptr != NULL){
        char myString[100];
        while(fgets(myString, 100, fptr)){
        printf("%s", myString);
        }
    }
    else{
        printf("Unable to open the file");
    }
    fclose(fptr);
}