#include <stdio.h>
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

int main() {
    long long p, g, a, b, A, B, secretKeyA, secretKeyB;

    // Step 1: Both parties agree on a large prime 'p' and a primitive root 'g'
    printf("Enter a prime number (p): ");
    scanf("%lld", &p);

    printf("Enter a primitive root modulo p (g): ");
    scanf("%lld", &g);

    // Step 2: Alice selects a private key 'a' and calculates 'A = g^a mod p'
    printf("Enter Alice's private key (a): ");
    scanf("%lld", &a);
    A = modExp(g, a, p);

    // Step 3: Bob selects a private key 'b' and calculates 'B = g^b mod p'
    printf("Enter Bob's private key (b): ");
    scanf("%lld", &b);
    B = modExp(g, b, p);

    // Step 4: Both parties exchange 'A' and 'B'

    // Step 5: Alice computes the shared secret key 'secretKeyA = B^a mod p'
    secretKeyA = modExp(B, a, p);

    // Step 6: Bob computes the shared secret key 'secretKeyB = A^b mod p'
    secretKeyB = modExp(A, b, p);

    // Both parties now have the same shared secret key
    printf("Shared secret key computed by Alice: %lld\n", secretKeyA);
    printf("Shared secret key computed by Bob: %lld\n", secretKeyB);
    
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");


    return 0;
}

