
#include <stdio.h>

int Fibonacci(int number, int first, int second)
{
    if (number == 0)
    {
        printf("%d ", number);
    }
    
    else if (number == 1)
    {
        printf("%d ", number);
    }

    else
    {
        
        printf("%d ", first);

        int next;

        next = first + second;
        first = second;

        return Fibonacci(number - 1, first, next);
    }
}

void main()
{
    int number;

    printf("\nEnter a number for fibonacci series: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Please enter a positive integer");
    }

    if (number == 0)
    {
        printf("Fibonacci series: 0");

    }

    else
    {
        printf("Fibonacci Series (%d terms): ", number);
        Fibonacci(number, 0, 1);

    }

}

