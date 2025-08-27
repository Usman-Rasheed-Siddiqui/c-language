
#include <stdio.h>

void main()

{
    int employee;
    float hours, amount, salary;

    printf("Enter employee ID: ");
    scanf("%d", &employee);

    printf("Enter work hours: ");
    scanf("%f", &hours);

    printf("Enter amount per hour: ");
    scanf("%f", &amount);

    salary = hours * amount;

    printf("Employee ID: %d \nSalary: %.2f PKR", employee, salary);
    
}