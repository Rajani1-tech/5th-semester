#include <stdio.h>

// Function to compute the GCD of two integers
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

    int result = gcd(num1, num2);

    printf("GCD of %d and %d is %d\n", num1, num2, result);
    
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");


    return 0;
}

