#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to perform Vigenère Cipher encryption
void vigenereEncrypt(char *message, char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);

    for (int i = 0; i < messageLength; i++) {
        char ch = message[i];
        char keyChar = key[i % keyLength];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            char keyBase = islower(keyChar) ? 'a' : 'A';
            message[i] = (ch - base + keyChar - keyBase) % 26 + base;
        }
    }
}

// Function to perform Vigenère Cipher decryption
void vigenereDecrypt(char *message, char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);

    for (int i = 0; i < messageLength; i++) {
        char ch = message[i];
        char keyChar = key[i % keyLength];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            char keyBase = islower(keyChar) ? 'a' : 'A';
            message[i] = (ch - base - (keyChar - keyBase) + 26) % 26 + base;
        }
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove the newline characters from the message and key
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == '\n') {
            message[i] = '\0';
            break;
        }
    }
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] == '\n') {
            key[i] = '\0';
            break;
        }
    }

    // Encrypt the message using the Vigenère Cipher
    vigenereEncrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the Vigenère Cipher
    vigenereDecrypt(message, key);
    printf("Decrypted message: %s\n", message);
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");

    return 0;
}

