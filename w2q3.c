#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void removePunctuation(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!ispunct(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char paragraph[10000];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int freq[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    toLowerCase(paragraph);
    removePunctuation(paragraph);

    char* token = strtok(paragraph, " \n\t");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordCount], token);
            freq[wordCount]++;
            wordCount++;
        }
        token = strtok(NULL, " \n\t");
    }
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
