#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDuplicate(char *s) {
    for(int i = 0; i < strlen(s); i++) {
        for(int j = i+1; j < strlen(s); j++) {
            if (s[i] == s[j] && s[i] != ' ') {
                return 1;
            }
        }
    }
    return 0;
}

int lengthOfLongestSubstring(char *s) {
    int length = strlen(s);
    char dest[100];
    int longest = 0;
    for(int i = 0; i < length; i++) {
        for(int j = 1; j <= length - i; j++) {
            strncpy(dest, s + i, j);
            if (isDuplicate(dest) == 1) {
                memset(dest, 0, j);
                break;
            } else {
                if (longest == 0 || j > longest) {
                    longest = j;
                }
            }
        }
    }
    return longest;
}

int main(int argc, char **argv) {
    int length = lengthOfLongestSubstring(argv[1]);
    printf("length of longest substring for string %s is: %d\n", argv[1], length);
    return 0;
}
