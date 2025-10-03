
#include <stdio.h>

void DecimaltoBinary(int decimal)
{
    if (decimal == 0)
    {
        return;
    }

    int binary, divide;
    
    divide = decimal / 2;
    binary = decimal % 2;

    DecimaltoBinary(divide);
    printf("%d", binary);

}

void main()
{
    int decimal;
    printf("\nEnter a decimal number: ");
    scanf("%d", &decimal);
    printf("Decimal Number of %d: ", decimal);

    if (decimal == 0)
    {
        printf("%d", decimal);
    }
    else
    {
    DecimaltoBinary(decimal);
    }
}

