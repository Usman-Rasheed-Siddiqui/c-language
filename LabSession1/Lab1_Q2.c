
#include <stdio.h>

void main()
{   
    float height, width, perimeter, area;

    printf("\nEnter height of rectangle: ");
    scanf("%f", &height);

    printf("Enter width of rectangle: ");
    scanf("%f", &width);

    perimeter = 2 * (height + width);
    area = height * width;

    printf("\nPerimeter of Rectangle: %.2f units", perimeter);
    printf("\nArea of Rectange: %.2f square units", area);    
}


