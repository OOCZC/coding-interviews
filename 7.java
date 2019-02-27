/*
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
     
    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }

}
*/

public class Solution {

    public TreeNode reConstructBinaryTree(int[] pre, int[] in) {

        if (pre == null || in == null) {
            return null;
        }

        return reConstructBinaryTree(pre, 0, pre.length - 1, in, 0, in.length - 1);
    }
    
    private TreeNode reConstructBinaryTree
            (int[] pre, int preL, int preR, int[] in, int inL, int inR) {

        if (preL > preR || inL > inR)
            return null;

        int root = pre[preL];
        int left_num = 0;

        for (left_num = 0; in[left_num + inL] != root; ++ left_num) {
            if (left_num + inL >= inR) {
                return null;
            }
        }

        TreeNode node = new TreeNode(pre[preL]);
        node.left = reConstructBinaryTree(pre, preL + 1, preL + left_num, in, inL, inL + left_num - 1);
        node.right = reConstructBinaryTree
              (pre, preL + left_num + 1, preR, in, inL + left_num + 1, inR);

        return node;
        
    }
   
}
