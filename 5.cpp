// 替换string中的空格为'%20'
// length 是字符串的总容量
#include <iostream>

void ReplaceBlank(char string[], int length){
    if(string == nullptr || length <= 0)
        return;
    int originalLength = 0;
    int blankNum = 0;
    for(int i = 0; string[i] != 0; ++i){
        originalLength ++;
        if(string[i] == ' ')
            blankNum ++;
    }
    int left = originalLength - 1;
    int right = originalLength - 1 + blankNum * 2;
    if(length <= right + 2) // 防止超出字符串容量
        return;
    string[right + 1] = 0;
    while(left >= 0){
        if(string[left] == ' '){
            left --;
            string[right--] = '0';
            string[right--] = '2';
            string[right--] = '%';
        }
        else{
            string[right--] = string[left--];
        }
    }
}

/*
int main(){
    char test[20] = "Hello world";
    ReplaceBlank(test, 20);
    std::cout << test << std::endl;
    return 0;
}
*/
