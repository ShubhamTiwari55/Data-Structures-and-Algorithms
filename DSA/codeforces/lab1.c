#include <stdio.h>

int matchesRegex(const char *str) {
    while (*str) {
        if (*str == 'a') {
            // Check for a*de
            str++;
            while (*str == 'a') {
                str++;
            }
            if (*str == 'd') {
                str++;
                if (*str == 'e') {
                    str++;
                } else {
                    return 0; // Invalid character after 'd'
                }
            } else {
                return 0; // Invalid character after 'a'
            }
        } else if (*str == 'b') {
            // Check for ab*c
            str++;
            while (*str == 'b') {
                str++;
            }
            if (*str == 'c') {
                str++;
            } else {
                return 0; // Invalid character after 'b'
            }
        } else if (*str == 'd') {
            // Check for (def)*
            str++;
            while (*str == 'd' || *str == 'e' || *str == 'f') {
                str++;
            }
        } else {
            return 0; // Invalid character
        }
    }
    return 1; // String matches the regex
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (matchesRegex(input)) {
        printf("\"%s\" matches the regex\n", input);
    } else {
        printf("\"%s\" does not match the regex\n", input);
    }
    return 0;
}