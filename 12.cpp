#include <stdio.h>
#include <iostream>
#include <memory.h>

// 这种flag和matrix矩阵第二维维数不确定的，用指针传递，手动取址
bool findPath(const char* matrix, int rows, int cols, 
              const char* str, bool* flag, int i, int j, int pathNum){
    if(str[pathNum] == 0)
        return true;
    if(i < 0 || i >= rows || j < 0 && j >= cols ||
       flag[i * cols + j] == true || matrix[i * cols + j] != str[pathNum])
        return false;
    flag[i * cols + j] = true;
    if(findPath(matrix, rows, cols, str, flag, i + 1, j, pathNum + 1) ||
       findPath(matrix, rows, cols, str, flag, i - 1, j, pathNum + 1) ||
       findPath(matrix, rows, cols, str, flag, i, j + 1, pathNum + 1) ||
       findPath(matrix, rows, cols, str, flag, i, j - 1, pathNum + 1))
        return true;
    else{
        flag[i * cols + j] = false;
        return false;
    }
}

bool hasPath(char* matrix, int rows, int cols, char* str){
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;
    bool* flag = new bool[rows * cols];
    memset(flag, 0, rows * cols);  // !!
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(findPath(matrix, rows, cols, str, flag, i, j, 0))
                return true;
        }
    }
    delete[] flag;
    return false;
}
/*
int main(){
    //char matrix[3][4] = {'a','b','c','e','s','f','c','s','a','d','e','e'};
    char matrix[] = "ABCESFCSADEE";
    char str[] = "ABCCED";
    std::cout << hasPath(matrix, 3, 4, str);
    return 0;
}
*/
