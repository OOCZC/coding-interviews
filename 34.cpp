vector<vector<int>> FindPath(TreeNode *root, int expectNumber){
    vector<vector<int>> ans;
    if(root == nullptr)
        return ans;
    int path[10000];
    addPath(root, path, 0, ans, expectNumber);
    return ans;
}

int addPath(TreeNode *root, int *path, int pathNum,
                            vector<vector<int>> &ans, int expectNumber){
    if(root -> left == nullptr && root -> right == nullptr){
        path[pathNum++] = root -> val;
        int sum = 0;
        for(int i = 0; i < pathNum; ++i){
            sum += path[i];
        }
        if(sum == expectNumber){
            vector<int> currentPath;
            for(int i = 0; i < pathNum; ++i){
                currentPath.push_back(path[i]);
            }
            ans.push_back(currentPath);
        }
        return 0;
    }
    path[pathNum++] = root -> val;
    if(root -> left != nullptr){
        addPath(root -> left, path, pathNum, ans, expectNumber);
    }
    if(root -> right != nullptr){
        addPath(root -> right, path, pathNum, ans, expectNumber);
    }
    return 0;
}
