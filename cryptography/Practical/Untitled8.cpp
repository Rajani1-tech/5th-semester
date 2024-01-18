#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to perform modular exponentiation (a^b mod m)
long long modExp(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b = b / 2;
    }

    return result;
}

// Function to perform a single iteration of the Rabin-Miller primality test with a fixed base of 2
bool rabinMillerTest(long long n, long long d, long long r) {
    long long x = modExp(2, d, n);
    if (x == 1 || x == n - 1) {
        return true;
    }

    for (int i = 0; i < r - 1; i++) {
        x = (x * x) % n;
        if (x == n - 1) {
            return true;
        }
    }

    return false;
}

// Function to perform the Rabin-Miller primality test
bool isPrimeRabinMiller(long long n, int k) {
    if (n <= 1 || n == 4) {
        return false;
    }
    if (n <= 3) {
        return true;
    }

    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    int r = 0;
    while (d % (1 << r) == 0) {
        r++;
    }

    for (int i = 0; i < k; i++) {
        if (!rabinMillerTest(n, d, r)) {
            return false;
        }
    }

    return true;
}

int main() {
    long long num;
    int iterations;

    printf("Enter a positive integer: ");
    scanf("%lld", &num);

    printf("Enter the number of iterations (recommended >= 10): ");
    scanf("%d", &iterations);

    if (isPrimeRabinMiller(num, iterations)) {
        printf("%lld is likely prime.\n", num);
    } else {
        printf("%lld is not prime.\n", num);
    }

    return 0;
}

