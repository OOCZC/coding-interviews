public class Solution {

    public TreeLinkNode GetNext(TreeLinkNode node) {

        if (node == null) {
            return null;
        }

        TreeLinkNode t = node, f = node;
        
        if (node.right != null) { // 有右子树
            t = node.right;
            while (t.left != null)
                t = t.left;
            return t;
        }
       
        // 无右子树
        f = node.next;
        while (f != null) {
            if (f.left == t) {
                return f;
            }
            if (f.right == t) {
                t = f;
                f = f.next;
            }
        }
        
        return f;
    }
}
