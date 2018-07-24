vector<int> PrintFromTopToBottom(TreeNode *root){
    vector<int> ans;
    if(root == nullptr)
        return ans;
    queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()){
        TreeNode *p = queue.front();
        queue.pop();
        ans.push_back(p -> val);
        if(p -> left != nullptr)
            queue.push(p -> left);
        if(p -> right != nullptr)
            queue.push(p -> right);
    }
    return ans;
}
