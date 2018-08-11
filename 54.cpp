/*
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};
*/

class Solution {
public:
    TreeNode* KthNode(TreeNode* root, int k) {
        TreeNode *Kth = nullptr;
        FindKthNode(Kth, root, k);
        return Kth;
    }
    void FindKthNode(TreeNode *&Kth, TreeNode *root, int &k) {
        if (root == nullptr || k < 1)
            return;
        FindKthNode(Kth, root -> left, k);
        if (k == 1) {
            Kth = root;
            -- k; // !!!  重要
            return;
        }
        -- k;
        FindKthNode(Kth, root -> right, k);
        return;
    }
};

/*

int main() {
    TreeNode *root = new TreeNode(8);
    root -> left = new TreeNode(6);
    root -> left -> left = new TreeNode(5);
    root -> left -> right = new TreeNode(7);
    root -> right = new TreeNode(10);
    root -> right -> left = new TreeNode(9);
    root -> right -> right = new TreeNode(11);
    int k;
    cin >> k;
    Solution a;
    TreeNode *p = a.KthNode(root, k);
    if(p == nullptr)
        cout << "no\n";
    else
        cout << p -> val << endl;
}
*/
