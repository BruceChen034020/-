/***********************
 * 藥理學複習軟體程式碼
 * 鍾博丞 Otis Chung
 * 2021/6/23
 * 版本: 2.0.0.0
 * 限制: 最多65536個藥名
 ***********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXWORDBANKSIZE 65536

/* 程式進入點 */
int main() {
    FILE *A;
    int N;  // number of drugs
    int i;
    int random;
    char **wordBank;  // 藥名 word bank
    char input[1024];

    srand(rand());  // 設定亂數種子
    N = 0;
    wordBank = (char **)malloc(MAXWORDBANKSIZE * sizeof(char *));

    A = fopen("神內精神麻醉藥物_newline.txt", "r");
    if (A == NULL) {
        perror("open file failed");
        exit(1);
    }

    printf("藥理學複習軟體\n本程式隨機輸出一個藥物名稱，請你說出他的適應症和作用機轉。\n");
    printf("本程式最多可以有%d個藥\n", MAXWORDBANKSIZE);
    while (fgets(input, 1024, A) != NULL && N < MAXWORDBANKSIZE) {
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] =  '\0';
        }
        wordBank[N++] = strdup(input);
    }

    if (N == MAXWORDBANKSIZE) {
        fprintf(stderr, "已超過本程式可容納%d個藥，請聯絡開發者\n", MAXWORDBANKSIZE);
        exit(1);
    }
    
    printf("資料庫有%d個藥\n", N);
    printf("Windows: Use ctrl + z to terminate process.\n");
    printf("Linux: Use ctrl + d to terminate process.\n");

    while ((i = getchar()) != EOF) {
        random = rand() % N;  // 產生 0~N 的亂數
        printf("%s\n", wordBank[random]);
    }

    for (i = 0; i < N; ++i) {
        free(wordBank[i]);
    }
    free(wordBank);

    return 0;
}
