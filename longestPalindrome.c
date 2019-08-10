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
            return isPalindrome(copy);
        } else {
            return 0;
        }
    }
}

char *longestPalindrome(char *s) {

}

int main(int argc, char **argv) {

}