class Solution {
    // last 表示前一个结点
    private TreeNode last = null;
    public TreeNode Convert(TreeNode root) {
        if (root == null)
            return root;
        ConvertNode(root);
        while (root.left != null)
            root = root.left;
        return root;
    }
     
    private void ConvertNode(TreeNode root) {
        if (root == null)
            return;
        ConvertNode(root.left);
        root.left = last;
        if (last != null) {
            last.right = root;
        }
        last = root;
        ConvertNode(root.right);
    }
}
