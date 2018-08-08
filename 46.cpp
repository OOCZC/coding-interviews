#include <iostream>
#include <string>
using namespace std;

bool isCount(char second, char first);

int GetTranslationCount(int number){
    if(number < 0){
        printf("0\n");
        return 0;
    }
    string num = to_string(number);
    int *dp = new int[num.size() + 1];
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= num.size(); ++i){
        if(isCount(num[i - 1], num[i - 2]))
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1];
    }
    printf("%d\n", dp[num.size()]);
    return dp[num.size()];
}

bool isCount(char second, char first){
    if(first == '0')
        return false;
    int encode = (first - '0') * 10 + second - '0';
    if(encode < 26)
        return true;
    else
        return false;
}

int main(){
    GetTranslationCount(0);
    GetTranslationCount(10);
    GetTranslationCount(125);
    GetTranslationCount(126);
    GetTranslationCount(426);
    GetTranslationCount(100);
    GetTranslationCount(101);
    GetTranslationCount(12258);
    GetTranslationCount(-100);
    return 0;
}
