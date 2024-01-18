#include <stdio.h>

// Function to calculate the GCD (Greatest Common Divisor) of two numbers
int gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int g = gcd(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return g;
}

int main() {
    int a, b, x, y;

    printf("Enter two integers (a and b): ");
    scanf("%d %d", &a, &b);

    int commonDivisor = gcd(a, b, &x, &y);

    printf("GCD(%d, %d) = %d\n", a, b, commonDivisor);
    printf("Coefficients (x, y) that satisfy %d * x + %d * y = %d are: (%d, %d)\n", a, b, commonDivisor, x, y);
    
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");


    return 0;
}

