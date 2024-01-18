#include <stdio.h>
#include <string.h>

// Function to encrypt a message using the Rail Fence Cipher
void railFenceEncrypt(char *message, int rails) {
    int messageLength = strlen(message);
    char encryptedMessage[100] = {0};
    int railIndex = 0;
    int railDirection = 1; // 1 for down, -1 for up

    for (int i = 0; i < messageLength; i++) {
        encryptedMessage[railIndex] = message[i];
        railIndex += railDirection;

        // Change direction when reaching the top or bottom rail
        if (railIndex == 0 || railIndex == rails - 1) {
            railDirection = -railDirection;
        }
    }

    printf("Encrypted message: %s\n", encryptedMessage);
}

// Function to decrypt a message encrypted using the Rail Fence Cipher
void railFenceDecrypt(char *encryptedMessage, int rails) {
    int messageLength = strlen(encryptedMessage);
    char decryptedMessage[100] = {0};
    int railIndex = 0;
    int railDirection = 1; // 1 for down, -1 for up

    for (int i = 0; i < messageLength; i++) {
        decryptedMessage[i] = encryptedMessage[railIndex];
        railIndex += railDirection;

        // Change direction when reaching the top or bottom rail
        if (railIndex == 0 || railIndex == rails - 1) {
            railDirection = -railDirection;
        }
    }

    printf("Decrypted message: %s\n", decryptedMessage);
}

int main() {
    char message[100];
    int rails;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    // Remove the newline character from the message
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == '\n') {
            message[i] = '\0';
            break;
        }
    }

    railFenceEncrypt(message, rails);

    // Decrypt the message
    railFenceDecrypt(message, rails);
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");

    return 0;
}

