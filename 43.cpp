class Solution{
public:
    int NumberOf1Between1AndN_Solution(int n){
        if(n < 1)
            return 0;
        char str[50];
        sprintf(str, "%d", n);
        return get1Num(str);
    }
    int get1Num(const char* str){
        if(str == nullptr || str[0] > '9' || str[0] < '0')
            return 0;
        int length = strlen(str);
        int numberOfFirst = 0;
        if(str[0] == '1')
            numberOfFirst = atoi(str + 1) + 1;
        else if(str[0] == '0')
            numberOfFirst = 0;
        else
            numberOfFirst = powerBase10(length - 1);
        return powerBase10(length - 2) * (length - 1)
               * (str[0] - '0') + numberOfFirst + get1Num(str + 1);
            
    }
    int powerBase10(int length){
        int ans = 1;
        for(int i = 0; i < length; ++i){
            ans *= 10;
        }
        return ans;
    }
};

/*
int main(){
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(21345) << endl;
    cout << s.NumberOf1Between1AndN_Solution(1000);
    return 0;
}
*/
