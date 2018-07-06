#include <stdio.h>

void reOrderArray(int* data, int length){
    if(data == nullptr || length <= 0)
        return;
    int i = 0, j = length - 1;
    while(i < j){
        while((data[i] & 0x1) == 1 && i < j){
            ++ i;
        }
        while((data[j] & 0x1) == 0 && i < j){
        // == 运算符优先级高于位运算&, 所以要加括号
            -- j;
        }
        if(i < j){
            // exchange(data[i], data[j]);
            data[i] ^= data[j];
            data[j] ^= data[i];
            data[i] ^= data[j];
            // data[i] ^= data[j] ^= data[i] ^= data[j];
        }
    }
    return;
}

// 可扩展的解法
void reOrderArray_(int* data, int length, bool (*func)(int)){
    if(data == nullptr || length <= 0)
        return;
    int i = 0, j = length - 1;
    while(i < j){
        while(func(data[i]) && i < j){
            ++ i;
        }
        while(!func(data[j]) && i < j){
        // == 运算符优先级高于位运算&, 所以要加括号
            -- j;
        }
        if(i < j){
            // exchange(data[i], data[j]);
            data[i] ^= data[j];
            data[j] ^= data[i];
            data[i] ^= data[j];
            // data[i] ^= data[j] ^= data[i] ^= data[j];
        }
    }
    return;
}

// 满足函数的放数组前面 
bool isOu(int i){
    return i % 2 == 0? false: true;
}

int main(){
    int a[] = {1,2,3,4,5,6,7};
    reOrderArray_(a, 7, isOu);
    for(int i = 0; i < 7; ++i)
        printf("%d ", a[i]);
    return 0;
}
