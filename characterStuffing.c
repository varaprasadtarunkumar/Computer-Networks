#include <stdio.h>
#include <string.h>
int main() {
    char flag = 'd';   // Flag character
    //char esc = 'E';    // Escape character
    char input[100];   // Input string
    char stuffed[200]; // Stuffed string
    int i, j = 0;

    printf("Enter the input string: ");
    gets(input); // Input string

    // Stuffing
    stuffed[j++] = flag; // Add flag at the beginning

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == flag ) {
            stuffed[j++] = flag; // Add escape character
        }
        stuffed[j++] = input[i]; // Add input character
    }

    stuffed[j++] = flag; // Add flag at the end
    stuffed[j] = '\0';   // Add null character at the end

    printf("Stuffed string: %s\n", stuffed); // Display stuffed string

    return 0;
}
