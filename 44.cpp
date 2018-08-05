#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int getIndex(int digit);

int getNumByIndex(int digit, int num);

int beginOfdigit(int digit){
    if(digit < 1)
        return -1;
    if(digit == 1)
        return 0;
    return (int)std::pow(10, digit - 1);
}

int digitAtIndex(int index){
    if(index < 0)
        return -1;
    index ++; // 从0开始
    int indexSum = 0, digit = 1;
    while(true){
        int indexNum = getIndex(digit) * digit;
        if(indexSum + indexNum < index)
            indexSum += indexNum;
        else
            return getNumByIndex(digit, index - indexSum);
        digit ++;
    }
}

int getIndex(int digit){
    if(digit < 1)
        return 0;
    if(digit == 1)
        return 10;

    int num = 90;
    digit -= 2;

    while(digit--){
        num *= 10;
    }
    return num;
}

// digit位数的第num个数字
int getNumByIndex(int digit, int num){
    int numberOfNumber;
    int indexOfNumber;
    if(num % digit == 0){
        numberOfNumber = num / digit;
        indexOfNumber = digit;
    }
    else{
        numberOfNumber = num / digit + 1;
        indexOfNumber = num % digit;
    }
    int ansNum = beginOfdigit(digit);
    ansNum += numberOfNumber - 1;
    char str[100];
    sprintf(str, "%d", ansNum);

    return str[indexOfNumber - 1] - '0';
}

int main(){
    cout << digitAtIndex(0) << endl;
    cout << digitAtIndex(1) << endl;
    cout << digitAtIndex(9) << endl;
    cout << digitAtIndex(10) << endl;
    cout << digitAtIndex(189) << endl;
    cout << digitAtIndex(190) << endl;
    cout << digitAtIndex(1000) << endl;
    cout << digitAtIndex(1001) << endl;
    cout << digitAtIndex(1002) << endl;
    return 0;
}
