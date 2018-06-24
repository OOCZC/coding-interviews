// 有序二维数组中查找某数是否存在
bool Find(int target, const vector<vector<int> >& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0;
    int col = cols - 1;
    if(row < 0 || col < 0)
        return false;
    while(col >= 0 && row < rows){
        if(matrix[row][col] > target){
            col -= 1;
        }
        else if(matrix[row][col] == target){
            return true;
        }
        else{
            row += 1;
        }
    }
    return false;
}
