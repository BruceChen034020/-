/* �Ĳz�ǽƲ߳n��{���X
�����o Bruce Chen
2021/6/21
����: 1.0.0.0
����: �̦h50000���ĦW�A�C���ĦW�̪�20�r�� */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Global variable */
char DrugBuffer[1000000]; // �����믫�¾K�Ī�.txt ���Ȧs
char WordBank[50000][21]; // �ĦW word bank
int N; // number of drugs

/* �{���i�J�I */
int main(){
    printf("�Ĳz�ǽƲ߳n��\r\n���{���H����X�@���Ī��W�١A�ЧA���X�L���A���g�M�@�ξ���C\r\n");
    FILE* A = fopen("�����믫�¾K�Ī�.txt", "r");
    int i;
    for(i=0; i<50000; i++){
        int f = fscanf(A, "%s", WordBank[i]);
        if(f != 1){
            break;
        }
        if(strlen(WordBank[i]) > 20){
            printf("ĵ�i: ���Ī��W�ٹL���C���p���}�o��!\r\n�}�o��: �����o Bruce Chen\r\n");
        }
    }
    N = i;
    printf("��Ʈw��%d����\r\n", N);
    if(N >= 50000){
        printf("ĵ�i: ��Ʈw�Ī��L�h�C���p���}�o��!\r\n�}�o��: �����o Bruce Chen\r\n");
    }
    srand(time(NULL)); // �]�w�üƺؤl
    system("pause");
    while(1){
        int r = rand() % N; // ���� 0~N ���ü�
        printf(WordBank[r]);
        printf("\r\n");
        system("pause");
    }
    return 0;
}
