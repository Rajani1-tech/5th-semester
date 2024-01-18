#include <stdio.h>
#include <ctype.h>

// Function to perform the shift cipher encryption
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            message[i] = (ch - base + shift) % 26 + base; // Encryption
        }
    }
}

// Function to perform the shift cipher decryption
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            message[i] = (ch - base - shift + 26) % 26 + base; // Decryption
        }
    }
}

int main() {
    char message[100];
    int shift;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // Remove the newline character from the message
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == '\n') {
            message[i] = '\0';
            break;
        }
    }

    // Encrypt the message
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}

