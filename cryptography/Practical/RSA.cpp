#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the modular exponentiation (a^b mod n)
long long mod_exp(long long a, long long b, long long n) {
    long long result = 1;
    a = a % n;
    
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % n;
        }
        a = (a * a) % n;
        b = b / 2;
    }
    
    return result;
}

int main() {
    // Generate small RSA key pairs (for demonstration only, use larger keys in practice)
    long long p = 61;  // prime number
    long long q = 53;  // prime number
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e = 17;  // public exponent
    long long d;

    // Find the private exponent (d) using the Extended Euclidean Algorithm
    for (d = 2; d < phi; d++) {
        if ((e * d) % phi == 1) {
            break;
        }
    }

    // Message to be encrypted and decrypted
    char message[] = "HELLO";

    // Encrypt the message
    char encrypted[256];
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = mod_exp(message[i], e, n);
    }
    encrypted[strlen(message)] = '\0';

    // Decrypt the message
    char decrypted[256];
    for (int i = 0; i < strlen(message); i++) {
        decrypted[i] = mod_exp(encrypted[i], d, n);
    }
    decrypted[strlen(message)] = '\0';

    printf("Original Message: %s\n", message);
    printf("Encrypted Message: %s\n", encrypted);
    printf("Decrypted Message: %s\n", decrypted);
    
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");


    return 0;
}

