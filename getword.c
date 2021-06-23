#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    FILE *A, *B;
    struct stat stbuf;
    char *input, *output;
    char *inptr, *outptr;

    A = fopen("神內精神麻醉藥物.txt", "r");
    if (A == NULL) {
        perror("open 神內精神麻醉藥物.txt failed");
        exit(1);
    }
    B = fopen("getword.txt", "w");
    if (B == NULL) {
        perror("open getword.txt failed");
        exit(1);
    }

    setvbuf(B, NULL, _IOFBF, 4096);

    fstat(fileno(A), &stbuf);
    input = (char *)calloc(stbuf.st_size, sizeof(char));
    output = (char *)calloc(stbuf.st_size, sizeof(char));
    inptr = input;
    outptr = output;

    fread(input, sizeof(char), stbuf.st_size, A);

    while (*inptr) {
        if (*inptr != ',') {
            *outptr++ = *inptr++;
        } else {
            ++inptr;
            *outptr++ = '\n';
            if (*inptr == ' ') {
                ++inptr;
            }
        }
    }
    *outptr++ = '\n';
    *outptr = '\0';

    fwrite(output, sizeof(char), strlen(output), B);

    free(input);
    free(output);
    fclose(A);
    fclose(B);
    return 0;
}
