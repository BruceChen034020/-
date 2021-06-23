/* 藥理學複習軟體程式碼
陳光穎 Bruce Chen
2021/6/21
版本: 1.0.0.0
限制: 最多50000個藥名，每個藥名最長20字元 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Global variable */
// char DrugBuffer[1000000];  // 神內精神麻醉藥物.txt 的暫存
// char WordBank[50000][21];  // 藥名 word bank
int N;                     // number of drugs

/* 程式進入點 */
int main() {
    FILE *A;
    int i;
    char **wordBank;

    srand(rand());
    wordBank = (char **)malloc(4096 * sizeof(char *));
    for (int i = 0; i < 4096; ++i) {
        wordBank[i] = calloc(32, sizeof(char));
    }
    A = fopen("神內精神麻醉藥物.txt", "r");
    if (A == NULL) {
        perror("open file failed");
        exit(1);
    }

    printf("藥理學複習軟體\n本程式隨機輸出一個藥物名稱，請你說出他的適應症和作用機轉。\n");
    for (i = 0; i < 50000; i++) {
        int f = fscanf(A, "%s", wordBank[i]);
        if (f != 1) {
            break;
        }
        if (strlen(wordBank[i]) > 20) {
            printf("警告: 有藥物名稱過長。請聯絡開發者!\n開發者: 陳光穎 Bruce Chen\n");
        }
    }
    N = i;
    printf("資料庫有%d個藥\r\n", N);
    if (N >= 50000) {
        printf("警告: 資料庫藥物過多。請聯絡開發者!\n開發者: 陳光穎 Bruce Chen\n");
    }
    srand(time(NULL));  // 設定亂數種子
    // system("pause");
    printf("Windows: Use ctrl + z to terminate process.\n");
    printf("Linux: Use ctrl + d to terminate process.\n");

    while ((i = getchar()) != EOF) {
        int r = rand() % N;  // 產生 0~N 的亂數
        printf("%s\n", wordBank[r]);
        // printf("\n");
        // system("pause");
    }

    for (int i = 0; i < 4096; ++i) {
        free(wordBank[i]);
    }
    free(wordBank);

    return 0;
}
