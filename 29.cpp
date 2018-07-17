vector<int> printMatrix(vector<vector<int>> matrix){
    int circleNum = 0;
    vector<int> ans;
    while(circleNum * 2 < matrix.size() && circleNum * 2 < matrix[0].size()){
        printCircle(circleNum, ans, matrix);
        circleNum ++;
    }
    return ans;
}


void printCircle(int circleNum, vector<int>& ans,const vector<vector<int>>& matrix){
    if(circleNum < 0)
        return;
    int endX = matrix.size() - 1 - circleNum;
    int endY = matrix[0].size() - 1 - circleNum;
    int i, j;
    for(j = circleNum; j <= endY; ++j){
        ans.push_back(matrix[circleNum][j]);
    }
    if(endX > circleNum){
        for(j = endY, i = circleNum + 1; i < matrix.size() - circleNum; ++i){
            ans.push_back(matrix[i][j]);
        }
    }
    if(endY > circleNum && endX > circleNum){
        for(i = endX, j = endY - 1; j >= circleNum; --j){
            ans.push_back(matrix[i][j]);
        }
    }
    if(endX > circleNum + 1 && endY > circleNum){
        for(i = endX - 1, j = circleNum; i >= circleNum + 1; --i){
            ans.push_back(matrix[i][j]);
        }
    }
}
