#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *s) {
    int length = strlen(s);
    if (length == 1) {
        return 1;
    } else if (length == 2) {
        if (s[0] == s[1]) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (s[0] == s[length - 1]) {
            char copy[1000];
            strncpy(copy, s + 1, length - 2);
            copy[length - 2] = '\0';
            return isPalindrome(copy);
        } else {
            return 0;
        }
    }
}

char *longestPalindrome(char *s) {
     char temp[1000];
     int length = strlen(s);
     int longest = 0;
     char *result = malloc(sizeof(char) * 1000);
     for(int i = 0; i < length; i++) {
         for(int j = 1; j <= length - i; j++) {
             strncpy(temp, s + i, j);
             if (isPalindrome(temp)) {
                 if (longest == 0 || j > longest) {
                     longest = j;
                     memset(result, 0, 1000);
                     strcpy(result, temp);
                 }
             } else {
                 memset(temp, 0, j);
             }
         }
     }
     return result;
}

int main(int argc, char **argv) {
    char *longest = longestPalindrome(argv[1]);
    printf("longest palindrome for string %s is %s\n", argv[1], longest);
    return 0;
}