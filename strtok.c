#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char *input;
    char *output;
    char *inputptr;
    char *outputptr;
    char *saveptr;
    char delm[] = ", \n\0";
    int openfd, writefd;
    int filesize;    

    openfd = open("神內精神麻醉藥物.txt", O_RDONLY, S_IRUSR);
    if (openfd < 0) {
        perror("open file error");
        exit(1);
    }
    filesize = lseek(openfd, 0, SEEK_END);
    input = (char *)calloc(filesize, sizeof(char));
    output = (char *)calloc(filesize * 2, sizeof(char));
    inputptr = input;
    outputptr = output;

    lseek(openfd, 0, SEEK_SET);
    read(openfd, input, filesize);

    writefd = open("神內精神麻醉藥物.txt", O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (writefd < 0) {
        perror("open file error");
        exit(1);
    }
    inputptr = strtok_r(inputptr, delm, &saveptr);
    
    strcat(output, "");
    strcat(output, inputptr);
    strcat(output, "\n");
    while (inputptr != NULL) {
        inputptr = strtok_r(NULL, delm, &saveptr);
        if (inputptr != NULL) {
            strcat(output, inputptr);
            strcat(output, "\n");
        }
    }

    // printf("%s", output);

    write(writefd, output, strlen(output));


    free(input);
    free(output);
    close(openfd);
    close(writefd);

    return 0;
}
