#include <stdio.h>

// Function to calculate the GCD (Greatest Common Divisor) of two numbers
int gcdExtended(int a, int b, int *x, int *y) {
    // Base Case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of the recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to compute the multiplicative inverse of an integer modulo m
int multiplicativeInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, &x, &y);

    if (gcd != 1) {
        // The multiplicative inverse does not exist
        return -1;
    } else {
        // Ensure the result is positive
        int result = (x % m + m) % m;
        return result;
    }
}

int main() {
    int num, mod;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter the modulo (positive integer): ");
    scanf("%d", &mod);

    if (mod <= 0) {
        printf("Invalid input for modulo. Please enter a positive integer.\n");
    } else {
        int inverse = multiplicativeInverse(num, mod);

        if (inverse == -1) {
            printf("The multiplicative inverse does not exist for %d modulo %d\n", num, mod);
        } else {
            printf("The multiplicative inverse of %d modulo %d is %d\n", num, mod, inverse);
        }
    }
    
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");


    return 0;
}

