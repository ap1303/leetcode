#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * longestCommonPrefix(char ** strs, int strsSize, int minLength){
    int longestIndex = 0;
    for(int w = 0; w < minLength; w++) {
        longestIndex = w;
        char entry = strs[0][w];
        int common = 1;
        for(int z = 1; z < strsSize; z++) {
            char letter = strs[z][w];
            if (letter != entry) {
                common = 0;
                break;
            }
        }
        if (common == 0) {
            break;
        }  
    }
    char *result = malloc(sizeof(char) * longestIndex);
    strncpy(result, strs[0], longestIndex);
    return result;
}

int main(int argc, char **argv) {
    int minLength = 0;
    for(int i = 1; i < argc; i++) {
        if (minLength == 0) {
            minLength = strlen(argv[i]);
        } else if (strlen(argv[i]) < minLength) {
            minLength = strlen(argv[i]);
        }
    }
    char **copy = (char **) malloc(sizeof(char *) * (argc - 1));
    for(int i = 0; i < argc - 1; i++) {
        copy[i] = (char *) malloc(sizeof(char) * minLength);
    }
    for(int i = 0; i < argc - 1; i++) {
        strcpy(copy[i], argv[i + 1]);
    }
    char *result = longestCommonPrefix(copy, argc - 1, minLength);
    printf("the longest common prefix is: %s\n", result);
    return 0;
}

