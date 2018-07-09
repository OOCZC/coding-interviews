// 返回二叉树的镜像

void Mirror(TreeNode *pRoot){
    if(pRoot == nullptr)
        return;
    TreeNode *temp;
    temp = pRoot -> left;
    pRoot -> left = pRoot -> right;
    pRoot -> right = temp;
    Mirror(pRoot -> left);
    Mirror(pRoot -> right);
    return;
}
