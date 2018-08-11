class Solution {
public:
    // 判断是否为平衡二叉树，所有节点左右子树深度相差不超过1
    bool IsBalanced_Solution(TreeNode *root) {
        bool flag = true;
        GetTreeDepth(root, flag);
        return flag;
    }

    int GetTreeDepth(TreeNode* root, bool &flag) {
        if (root == nullptr)
            return 0;
        int left = GetTreeDepth(root -> left, flag);
        int right = GetTreeDepth(root -> right, flag);
        if(abs(left - right) > 1) {
            flag = false; 
            return 0;
        }
        return max(left, right) + 1;
    }
};
