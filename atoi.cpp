#include <iostream>
using namespace std;	

class Solution {
public:
    int StrToInt(string str) {
        long long num = 0; // 用long long 累计和
        int flag = 1;
        int i = 0;
        if (str[i] == '+') {
            flag = 1;
            ++ i;
        }
        else if (str[i] == '-') {
            flag = -1;
            ++ i;
        }
        cout << i << endl;
        for (; i < str.size(); ++i) {
            if (str[i] < '0' || str[i] > '9') 
                return 0;
            
            num *= 10;
            num += str[i] - '0';
            if ((flag == 1 && num > INT_MAX) || (flag == -1 && num < INT_MIN)) // 溢出
                return 0;
        }
        return int(num) * flag;
    }
};

/*
int main() {
    Solution s;
    string str("123");
    cout << s.StrToInt(str) << endl;
    return 0;
}
*/
