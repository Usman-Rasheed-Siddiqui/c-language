
#include <stdio.h>

void main()
{
    float height;

    printf("Enter your height (in cm): ");
    scanf("%f", &height);

    if (height < 150)
    {
        printf("Drawf");
    }
    else if (height == 150)
    {
        printf("Average");
    }
    else
    {
        printf("Tall");
    }
}