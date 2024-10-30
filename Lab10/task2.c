#include <stdio.h>
#include <stdlib.h>

int StrengLength(char *text);
void getInput(char **text, int size);
void reverseString(char *text, char **reverse, int length);

int main() {
    int a; 
    printf("Enter the size of the string: ");
    scanf("%d", &a);

    char *text = malloc(a * sizeof(char));
    if (text == NULL) { 
        printf("No memory allocated\n");
        return 1;
    }

    getInput(&text, a); 

    int length = StrengLength(text); 
    printf("Length: %d\n", length);

    char *reverse = malloc((length + 1) * sizeof(char));
    if (reverse == NULL) {
        printf("No memory allocated for reverse\n");
        free(text);
        return 1;
    }

    reverseString(text, &reverse, length);
    printf("Reversed: %s\n", reverse);

    free(text);
    free(reverse);

    return 0;
}

int StrengLength(char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
        count++;
    }
    return count;
}

void getInput(char **text, int size) {
    printf("Please enter text: ");
    getchar();
    fgets(*text, size, stdin); 
}

void reverseString(char *text, char **reverse, int length) {
    for(int j = 0; j < length; j++) {
        (*reverse)[j] = text[length - 1 - j];
    }
    (*reverse)[length] = '\0';
}

