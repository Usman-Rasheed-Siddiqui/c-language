
#include <stdio.h>

int main(){
    FILE *fptr;
    int ch;
    int count = 0;
    fptr = fopen("Lab5.txt", "r");
    if (fptr != NULL){
        printf("Text from file:\n");
        while((ch = getc(fptr)) != EOF){
            printf("%c", ch);
            if (ch == ' ' || ch == '\n' || ch=='\t'){
                count++;
            }
        }
    }
    else{
        printf("Unable to open the file");
    }
    fclose(fptr);
    count++;

    printf("\nNumber of words: %d", count);

    return 0;
}
