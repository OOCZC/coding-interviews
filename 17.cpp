#include <stdio.h>
#include <memory.h>
void increase(char* number, int length);
void printNumber(char* number, int length);

void Print1ToMaxOfDigits(int n){
    if(n <= 0)
        return;
    char* number = new char[n + 2];
    memset(number, 0, n + 2);
    while(number[0] == 0){
        increase(number, n + 1);
        printNumber(number, n + 1);
    }
    delete[] number;
}

void increase(char* number, int length){
    number[length - 1] ++;
    for(int i = length - 1; i >= 0; --i){
        if(number[i] >= 10){
            number[i] = number[i] % 10;
            number[i - 1] ++;
        }
        else
            break;
    }
}

void printNumber(char* number, int length){
    int isBeginning0 = 1;
    while(number[isBeginning0] == 0)
        ++ isBeginning0;
    for(; isBeginning0 < length; ++isBeginning0){
        printf("%c", number[isBeginning0] + '0');
    }
    printf("\n");
}
/*
int main(){
    Print1ToMaxOfDigits(6);
    return 0;
}
*/
