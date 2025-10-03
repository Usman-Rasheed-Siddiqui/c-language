
#include <stdio.h>

struct Distance {
    int feet;
    int inches;
};

int main() {
    struct Distance distance1;

    printf("Distance 1:\n");
    printf("Enter feets: ");
    scanf("%d", &distance1.feet);
    printf("Enter inches: ");
    scanf("%d", &distance1.inches);

    while(distance1.inches>12) {
        distance1.inches -= 12;
        distance1.feet += 1;
    }

    struct Distance distance2;
    printf("Distance 2:\n");
    printf("Enter feets: ");
    scanf("%d", &distance2.feet);
    printf("Enter inches: ");
    scanf("%d", &distance2.inches);

    while(distance2.inches>12) {
        distance2.inches -= 12;
        distance2.feet += 1;
    }

    struct Distance sum;
    sum.feet = distance1.feet + distance2.feet;
    sum.inches = distance1.inches + distance2.inches;

    while(sum.inches>12) {
        sum.inches -= 12;
        sum.feet += 1;
    }

    printf("(%d ft %d inches) + (%d ft %d inches) = %d ft %d inches",
    distance1.feet, distance1.inches, distance2.feet, distance2.inches,
    sum.feet, sum.inches);

}


