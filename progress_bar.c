#include <stdio.h>
#include <unistd.h>

int main() {
    // setvbuf(stdout, NULL, _IOLBF, 4096);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("#");
        }
        printf("\r");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
    return 0;
}
