#include <stdio.h>

// Function to calculate the GCD (Greatest Common Divisor) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to compute the Totient of a number
int totient(int n) {
    int result = 1;

    for (int i = 2; i < n; i++) {
        if (gcd(n, i) == 1) {
            result++;
        }
    }

    return result;
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
    } else {
        int phi = totient(n);
        printf("The Totient (f) of %d is %d\n", n, phi);
    }
    
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");


    return 0;
}

