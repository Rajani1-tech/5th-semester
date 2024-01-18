#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to prepare the key matrix
void prepareKeyMatrix(char key[], char keyMatrix[5][5]) {
    int keyLength = strlen(key);
    int i, j, k;
    char usedChars[26] = {0}; // To keep track of used characters

    // Initialize the matrix with zeros
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            keyMatrix[i][j] = 0;
        }
    }

    i = 0;
    j = 0;

    for (k = 0; k < keyLength; k++) {
        char ch = toupper(key[k]);

        // Skip duplicate and non-alphabet characters
        if (usedChars[ch - 'A'] || !isalpha(ch))
            continue;

        usedChars[ch - 'A'] = 1;
        keyMatrix[i][j] = ch;
        j++;

        if (j == 5) {
            j = 0;
            i++;
        }
    }

    char fillChar = 'A';

    // Fill the remaining empty cells with other alphabet characters
    for (; i < 5; i++) {
        for (; j < 5; j++) {
            while (usedChars[fillChar - 'A'] || fillChar == 'J') {
                fillChar++;
            }
            keyMatrix[i][j] = fillChar;
            usedChars[fillChar - 'A'] = 1;
            fillChar++;
        }
        j = 0;
    }
}

// Function to find the positions of two characters in the key matrix
void findPositions(char keyMatrix[5][5], char ch, int *row, int *col) {
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of characters
void encryptPair(char keyMatrix[5][5], char a, char b) {
    int row1, col1, row2, col2;

    findPositions(keyMatrix, a, &row1, &col1);
    findPositions(keyMatrix, b, &row2, &col2);

    if (row1 == row2) {
        col1 = (col1 + 1) % 5;
        col2 = (col2 + 1) % 5;
    } else if (col1 == col2) {
        row1 = (row1 + 1) % 5;
        row2 = (row2 + 1) % 5;
    } else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }

    printf("%c%c", keyMatrix[row1][col1], keyMatrix[row2][col2]);
}

// Function to encrypt a message using the Playfair Cipher
void playfairEncrypt(char keyMatrix[5][5], char message[]) {
    int messageLength = strlen(message);
    int i;

    for (i = 0; i < messageLength; i += 2) {
        char a = toupper(message[i]);
        char b = toupper(message[i + 1]);

        if (a == 'J') a = 'I';
        if (b == 'J') b = 'I';

        if (a == b) {
            b = 'X';
            i--;
        }

        encryptPair(keyMatrix, a, b);
    }

    printf("\n");
}

int main() {
    char key[26];
    char message[100];
    char keyMatrix[5][5];

    printf("Enter the key (up to 25 unique characters): ");
    scanf("%s", key);

    printf("Enter the message to encrypt (in uppercase): ");
    scanf("%s", message);

    prepareKeyMatrix(key, keyMatrix);
    playfairEncrypt(keyMatrix, message);
    printf("Name: Rajani Lamichhane\n");
    printf("Rollno: 25796");

    return 0;
}

