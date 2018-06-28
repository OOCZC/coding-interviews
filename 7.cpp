// 根据二叉树先序和中序遍历构建二叉树
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
TreeNode* ConstructTree(int* startPreorder, int* endPreorder,
                        int* startInorder, int* endInorder){
    TreeNode* root = new TreeNode(*startPreorder);
    if(startPreorder == endPreorder){
        if(startInorder == endInorder &&
           *startInorder == *startPreorder)
            return root;
        else
            throw std::exception();

    }
    int* rootInorder = startInorder;
    while(rootInorder < endInorder && *rootInorder != *startPreorder){
        rootInorder ++;
    }
    if(rootInorder == endInorder && *rootInorder != *startPreorder){
        throw std::exception();
    }
    int leftLength = rootInorder - startInorder;
    if(startInorder - rootInorder < 0)
        root -> left = ConstructTree(startPreorder + 1, startPreorder + leftLength,
                                     startInorder, startInorder + leftLength - 1);
    if(endInorder - rootInorder > 0)
        root -> right = ConstructTree(startPreorder + leftLength + 1, endPreorder,
                                      startInorder + leftLength + 1, endInorder);
    return root;
}
    

TreeNode* Construct(int* preorder, int* inorder, int length){
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    return ConstructTree(preorder, preorder + length - 1,
                  inorder, inorder + length - 1);
}

