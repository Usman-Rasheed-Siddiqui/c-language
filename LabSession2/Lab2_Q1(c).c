

#include <stdio.h>

int main()
{
    int range;
    printf("Enter a range: ");
    scanf("%d", &range);

    printf("Odd Numbers:\n");
    int sum = 0;
    int i = 1;
    do{
        if (i%2==1) {
            printf("%d\n", i);
            sum += i;
        }
        i=i+1;
    }while (i <= range);

    printf("Sum of the odd numbers: %d", sum);
    return 0;
}



