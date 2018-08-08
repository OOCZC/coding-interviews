#include <iostream>
using namespace std;

int longestSubstringWithoutDuplication(const string &str){
    int *pos = new int[26]();
    int dp = 0;
    int MaxValue = 0;
    for(int i = 0; i < 26; ++i)
        pos[i] = -1;

    for(int i = 0; i < str.length(); ++i){
        int charPos = pos[str[i] - 'a'];
        if(charPos == -1 || i - charPos > dp)
            dp += 1;
        else
            dp = i - charPos;
        pos[str[i] - 'a'] = i;
        if(dp > MaxValue)
            MaxValue = dp;
    }

    delete[] pos;
    return MaxValue;
}

int main(){
    string test = "abcacfrar";
    cout << longestSubstringWithoutDuplication(test);
    return 0;
}
