class Solution {
public:
    int TreeDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return max(TreeDepth(root -> left), TreeDepth(root -> right)) + 1;
    }
};
