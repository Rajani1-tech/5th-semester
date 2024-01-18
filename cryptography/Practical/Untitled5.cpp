#include <stdio.h>

// Function to calculate the GCD (Greatest Common Divisor) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Calculate the GCD of the two numbers
    int commonDivisor = gcd(num1, num2);

    if (commonDivisor == 1) {
        printf("%d and %d are coprime (relatively prime)\n", num1, num2);
    } else {
        printf("%d and %d are not coprime\n", num1, num2);
    }
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");

    return 0;
}

