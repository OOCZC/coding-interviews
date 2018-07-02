#include <iostream>
#include <memory.h>
void dfs(bool* flag, const int threshold, int &ans, int i, int j, const int rows, const int cols);
int getSum(int i, int j);

int moving(int threshold, int rows, int cols){
    if(threshold < 0 || rows <= 0 || cols <= 0)
        return 0;
    bool* flag = new bool[rows * cols];
    memset(flag, 0, rows * cols);
    int ans = 0;
    dfs(flag, threshold, ans, 0, 0, rows, cols);

    delete[] flag;
    return ans;
}


void dfs(bool* flag, const int threshold, int &ans, int i, int j, const int rows, const int cols){
    if(i < 0 || i >= rows || j < 0 || j >= cols || flag[i * cols + j] == true)
        return;
    int sum = getSum(i, j);
    if(threshold < sum)
        return;
    ans += 1;
    flag[i * cols + j] = true;
    dfs(flag, threshold, ans, i + 1, j, rows, cols);
    dfs(flag, threshold, ans, i - 1, j, rows, cols);
    dfs(flag, threshold, ans, i, j + 1, rows, cols);
    dfs(flag, threshold, ans, i, j - 1, rows, cols);
    // flag[i * cols + j] = false;
}

int getSum(int i, int j){
    int sum = 0;
    while(i > 0 || j > 0){
        sum += i % 10;
        sum += j % 10;
        i /= 10;
        j /= 10;
    }
    return sum;
}

int main(){
    std::cout << moving(100, 5, 5);
    return 0;
}



