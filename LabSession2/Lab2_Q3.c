
#include <stdio.h>

int mystrcmp(char str1[], char str2[])
    {
    
        int i = 0;
        while(str1[i] !='\0' && str2[i] !='\0') {
            if(str1[i] != str2[i]){
                if(str1[i] < str2[i]) {
                    return -1;
                }
                else if (str1[i] > str2[i]){
                    return 1;
                }
            }
            i = i + 1;
        }

        if(str1[i] =='\0' && str2[i] =='\0') {
            return 0;
        }
        else if (str1[i] =='\0') {
            return -1;
        }
        else {
            return 1;
        }

    }

void main() {
    char str1[] = "She";
    char str2[] = "Sheep";

    int result = mystrcmp(str1, str2);

    if (result < 0){
        printf("%s is smaller than %s", str1, str2);
    }
    else if (result > 0){
        printf("%s is bigger than %s", str1, str2);
    }
    else {
        printf("Both strings are equal");
    }

}