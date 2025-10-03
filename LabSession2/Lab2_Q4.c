
#include <stdio.h>

void change(char str1[]) {
    int i = 0;
    while(str1[i] != '\0') {

        if(str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] -= 32; 
        }
        else if(str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] += 32; 
        }

        i = i + 1;
    }

    printf("Modified Sentence: %s", str1);
}

void main() {
    char sentence[] = "I study in a University";
    printf("Sentence: %s\n", sentence);
    change(sentence);
}


