
#include <stdio.h>

int main()
{   

    for( int a = 1; a<=4; a++) {

        for(int i=1; i<=(4-a); i++){
            printf(" ");
        }
        
        for(int j=1; j<=a; j++){
            printf("* ");
        }
        printf("\n");
    }
}

