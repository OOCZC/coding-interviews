#include <iostream>

using namespace std;

int GetMaxValue(const int *data, int row, int col){
    if(data == nullptr)
        return 0;
    int **dp = new int*[row]; // 二维数组动态申请
    for(int i = 0; i < row; ++i)
        dp[i] = new int[col]();

    dp[0][0] = data[0];
    for(int i = 1; i < col; ++i)
        dp[0][i] = data[i] + dp[0][i - 1];
    for(int i = 1; i < row; ++i)
        dp[i][0] = data[i * col] + dp[i - 1][0];
    for(int i = 1; i < row; ++i)
        for(int j = 1; j < col; ++j)
            dp[i][j] = data[i * col + j] + max(dp[i][j - 1], dp[i - 1][j]);
    
    int returnValue = dp[row - 1][col - 1];
    for(int i = 0; i < row; ++i)  // 二维数组释放
        delete[] dp[i];
    delete[] dp;
    return returnValue;
}


int main(){

    int values[][1] = {
        { 3 }
    };
    cout << GetMaxValue((const int*)values,1,1);
    return 0;
}
