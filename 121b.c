#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char is_spelled_out(char* line, int start, int end){
    if ((end - start) == 2) {
        if (line[start] == 'o' && line[start+1] == 'n' && line[start+2] == 'e') {
            return '1';
        }
        if (line[start] == 't' && line[start+1] == 'w' && line[start+2] == 'o') {
            return '2';
        }
        if (line[start] == 's' && line[start+1] == 'i' && line[start+2] == 'x') {
            return '6';
        }
    }
    else if ((end - start) == 3) {
        if (line[start] == 'f' && line[start+1] == 'o' && line[start+2] == 'u' && line[start+3] == 'r') {
            return '4';
        }
        if (line[start] == 'f' && line[start+1] == 'i' && line[start+2] == 'v' && line[start+3] == 'e') {
            return '5';
        }
        if (line[start] == 'n' && line[start+1] == 'i' && line[start+2] == 'n' && line[start+3] == 'e') {
            return '9';
        }
    }
    else if ((end - start) == 4) {
        if (line[start] == 't' && line[start+1] == 'h' && line[start+2] == 'r' && line[start+3] == 'e' && line[start+4] == 'e') {
            return '3';
        }
        if (line[start] == 's' && line[start+1] == 'e' && line[start+2] == 'v' && line[start+3] == 'e' && line[start+4] == 'n') {
            return '7';
        }
        if (line[start] == 'e' && line[start+1] == 'i' && line[start+2] == 'g' && line[start+3] == 'h' && line[start+4] == 't') {
            return '8';
        }
    }
    return 'x';
}

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
        //      printf("The %d element is %c", j, lines[i][j]);
                if isdigit(lines[i][j]) {
                    tmp[0] = lines[i][j];
                    break;
                }
                    if (is_spelled_out(lines[i], j, j+4) != 'x') {
//                      printf("found 5 letter number %c%c%c%c%c\n", lines[i][j], lines[i][j+1], lines[i][j+2], lines[i][j+3], lines[i][j+4]);
                        tmp[0] = is_spelled_out(lines[i], j, j+4);
                        break;
                    }
                    if (is_spelled_out(lines[i], j, j+3) != 'x') {
//                        printf("found 4 letter number %c%c%c%c\n", lines[i][j], lines[i][j+1], lines[i][j+2], lines[i][j+3]);
                        tmp[0] = is_spelled_out(lines[i], j, j+3);
                        break;
                    }
                    if (is_spelled_out(lines[i], j, j+2) != 'x') {
//                        printf("found 3 letter number %c%c%c\n", lines[i][j], lines[i][j+1], lines[i][j+2]);
                        tmp[0] = is_spelled_out(lines[i], j, j+2);
                        break;
                    }
            }
            for (int j = strlen(lines[i]); j > -1; j--) {
                if isdigit(lines[i][j]) {
                    tmp[1] = lines[i][j];
                    break;
                }
                    if (is_spelled_out(lines[i], j, j+4) != 'x') {
                        tmp[1] = is_spelled_out(lines[i], j, j+4);
                        break;
                    }
                    if (is_spelled_out(lines[i], j, j+3) != 'x') {
                        tmp[1] = is_spelled_out(lines[i], j, j+3);
                        break;
                    }
                    if (is_spelled_out(lines[i], j, j+2) != 'x') {
                        tmp[1] = is_spelled_out(lines[i], j, j+2);
                        break;
                    }
            }
            int tmpint = atoi(tmp);
         //   printf("The number is: %d\n", tmpint);
            count = count + tmpint;
        free(lines[i]);
    }
    free(lines);
    printf("%d\n", count);
    return 0;
}
