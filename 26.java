/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
 
    public TreeNode(int val) {
        this.val = val;
 
    }
 
}
*/
public class Solution {
    // 判断 root2 是否是 root1 的子结构，空树不算
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        if (root1 == null || root2 == null)
            return false;
        if (isSon(root1, root2))
            return true;
        else
            return false;
    }
 
    private boolean isSon(TreeNode root1, TreeNode root2) {
        if (root1 == null || root2 == null)
            return false;
        if (judgeSon(root1, root2))
            return true;
        return isSon(root1.left, root2) || isSon(root1.right, root2);
    }
 
    private boolean judgeSon(TreeNode root1, TreeNode root2) {
        if (root2 == null)
            return true;
        if (root1 == null)
            return false;
        if (root1.val == root2.val && judgeSon(root1.left, root2.left)
            && judgeSon(root1.right, root2.right))
            return true;
        return false;
    }
}

