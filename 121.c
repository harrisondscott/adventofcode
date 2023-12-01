#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
    char input[256];
    char tmp[2];
    char **lines = NULL;
    int numLines = 0;
    int i;
    int count = 0;

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            break;
        }

        char *newLine = malloc(strlen(input) + 1);
        strcpy(newLine, input);

        lines = realloc(lines, (numLines + 1) * sizeof(char *));
        lines[numLines] = newLine;
        numLines++;
    }


    for (i = 0; i < numLines; i++) {
            for (int j = 0; j < strlen(lines[i]); j++) {
                if isdigit(lines[i][j]) {
                    tmp[0] = lines[i][j];
                    break;
                }
            }
            for (int j = strlen(lines[i]); j > -1; j--) {
                if isdigit(lines[i][j]) {
                    tmp[1] = lines[i][j];
                    break;
                }
            }
            int tmpint = atoi(tmp);
            count = count + tmpint;
        free(lines[i]);
    }
    free(lines);
    printf("%d", count);
    return 0;
}
