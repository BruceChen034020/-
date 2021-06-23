#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *A; // 神內精神麻醉藥物.txt
    FILE *B; // output file
    int i; // iterator
    char buffer; // the currently reading character
    int f; // return of fscanf

    A = fopen("神內精神麻醉藥物.txt", "r");
    B = fopen("output.txt", "w");
    for(i=0; i<1000000; i++){
        f = fscanf(A, "%c", &buffer);
        if(f != 1){
            break;
        }
        if(buffer == ','){
            fscanf(A, "%c", &buffer);
            if(buffer == ' '){
                fprintf(B, "%c", '\n');
            }else{
                fprintf(B, "%c", buffer);
            }
        }else{
            fprintf(B, "%c", buffer);
        }
    }
    return 0;
}
