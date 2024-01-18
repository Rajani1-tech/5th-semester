#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2;

    // Input the two numbers
    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    // Check if num2 is the multiplicative inverse of num1
    double product = num1 * num2;

    // Check if the absolute difference between the product and 1 is very small (considering precision issues)
    if (fabs(product - 1.0) < 1e-9) {
        printf("%.9lf is the multiplicative inverse of %.9lf\n", num2, num1);
    } else {
        printf("%.9lf is not the multiplicative inverse of %.9lf\n", num2, num1);
        
   

    }
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");

    return 0;
}

