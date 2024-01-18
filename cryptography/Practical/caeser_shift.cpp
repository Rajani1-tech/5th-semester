#include <stdio.h>
#include <ctype.h>

// Function to perform Caesar Cipher encryption
void caesarEncrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            message[i] = (ch - base + shift) % 26 + base;
        }
    }
}

// Function to perform Caesar Cipher decryption
void caesarDecrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            message[i] = (ch - base - shift + 26) % 26 + base;
        }
    }
}

int main() {
    char message[100];
    int shift;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the shift value (a positive integer): ");
    scanf("%d", &shift);

    // Remove the newline character from the message
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == '\n') {
            message[i] = '\0';
            break;
        }
    }

    // Encrypt the message
    caesarEncrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesarDecrypt(message, shift);
    printf("Decrypted message: %s\n", message);
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");


    return 0;
}

