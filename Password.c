// C-code

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LEN 20

int processed_passwords = 0;

int is_vowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void analyze_password(const char *password) {
    static int vowel_count[5] = {0};
    int consonants = 0;
    register int i;

    for (i = 0; password[i] != '\0'; i++) {
        if (is_vowel(password[i])) {
            switch (tolower(password[i])) {
                case 'a': vowel_count[0]++; break;
                case 'e': vowel_count[1]++; break;
                case 'i': vowel_count[2]++; break;
                case 'o': vowel_count[3]++; break;
                case 'u': vowel_count[4]++; break;
            }
        } else {
            consonants++;
        }
    }

    int max_vowel_idx = 0;
    for (i = 1; i < 5; i++) {
        if (vowel_count[i] > vowel_count[max_vowel_idx]) {
            max_vowel_idx = i;
        }
    }

    char most_frequent_vowel = "aeiou"[max_vowel_idx];
    printf("Total vowels: %d, total consonants: %d\n",
        vowel_count[0] + vowel_count[1] + vowel_count[2] + vowel_count[3] + vowel_count[4], consonants);
    printf("Most Frequent Vowel: %c\n", most_frequent_vowel);
}

void filter_and_sort_password(const char *password) {
    char filtered[MAX_LEN];
    int index = 0;
    int i, j;

    // Filter vowels
    for (i = 0; password[i] != '\0'; i++) {
        if (!is_vowel(password[i])) {
            filtered[index++] = password[i];
        }
    }
    filtered[index] = '\0';

    // Sort filtered password
    for (i = 0; i < index - 1; i++) {
        for (j = i + 1; j < index; j++) {
            if (filtered[i] > filtered[j]) {
                char tmp = filtered[i];
                filtered[i] = filtered[j];
                filtered[j] = tmp;
            }
        }
    }

    printf("Filtered password (no vowels): %s\n", filtered);
}

int main() {
    char password[MAX_LEN + 1];
    printf("Enter a password (16-20 characters, no spaces): ");
    scanf("%s", password);

    int len = strlen(password);
    if (len < 16 || len > 20) {
        printf("Invalid password length. Must be 16-20 characters.\n");
        return 0;
    }

    processed_passwords++;
    analyze_password(password);
    filter_and_sort_password(password);
    printf("Total passwords processed: %d\n", processed_passwords);

    return 0;
}
