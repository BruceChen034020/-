/* 藥理學複習軟體程式碼
陳光穎 Bruce Chen
2021/6/21
版本: 1.0.0.0
限制: 最多50000個藥名，每個藥名最長20字元 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Global variable */
char DrugBuffer[1000000]; // 神內精神麻醉藥物.txt 的暫存
char WordBank[50000][21]; // 藥名 word bank
int N; // number of drugs

/* 程式進入點 */
int main(){
    printf("藥理學複習軟體\r\n本程式隨機輸出一個藥物名稱，請你說出他的適應症和作用機轉。\r\n");
    FILE* A = fopen("神內精神麻醉藥物.txt", "r");
    int i;
    for(i=0; i<50000; i++){
        int f = fscanf(A, "%s", WordBank[i]);
        if(f != 1){
            break;
        }
        if(strlen(WordBank[i]) > 20){
            printf("警告: 有藥物名稱過長。請聯絡開發者!\r\n開發者: 陳光穎 Bruce Chen\r\n");
        }
    }
    N = i;
    printf("資料庫有%d個藥\r\n", N);
    if(N >= 50000){
        printf("警告: 資料庫藥物過多。請聯絡開發者!\r\n開發者: 陳光穎 Bruce Chen\r\n");
    }
    srand(time(NULL)); // 設定亂數種子
    system("pause");
    while(1){
        int r = rand() % N; // 產生 0~N 的亂數
        printf(WordBank[r]);
        printf("\r\n");
        system("pause");
    }
    return 0;
}
