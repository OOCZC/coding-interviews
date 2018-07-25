TreeNode* Convert(TreeNode *root){
    if(root == nullptr)
        return nullptr;
    TreeNode *p = root, *last = nullptr;
    ConvertNode(root, last);
    while(p -> left != nullptr)
        p = p -> left;
    return p;
}

void ConvertNode(TreeNode *curr, TreeNode *&lastNode){
    if(curr == nullptr)
        return;
    if(curr -> left != nullptr)
        ConvertNode(curr -> left, lastNode);
    if(lastNode != nullptr){
        lastNode -> right = curr;
        curr -> left = lastNode;
    }
    lastNode = curr;
    if(curr -> right != nullptr){
        ConvertNode(curr -> right, lastNode);
    }
}
