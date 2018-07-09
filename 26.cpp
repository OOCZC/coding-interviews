/*

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
}

*/

// 判断树2是否为树1的子结构 (空树不是任意一个树的子结构)
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    bool ans = false;
    if(pRoot1 -> val == pRoot2 -> val)
        ans = isSubtree(pRoot1, pRoot2);
    ans = ans || HasSubtree(pRoot1 -> left, pRoot2) ||
          HasSubtree(pRoot1 -> right, pRoot2);
    return ans;
}

// 树1是否包含树2（头节点相同）
bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot2 == nullptr)
        return true;
    if(pRoot1 == nullptr)
        return false;
    if(pRoot1 -> val != pRoot2 -> val)
        return false;
    return isSubtree(pRoot1 -> left, pRoot2 -> left) &&
           isSubtree(pRoot1 -> right, pRoot2 -> right);
}
