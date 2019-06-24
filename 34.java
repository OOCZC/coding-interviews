import java.util.ArrayList;
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
    private ArrayList<ArrayList<Integer>> ans;
    private ArrayList<Integer> path;
     
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root, int target) {
        ans = new ArrayList<ArrayList<Integer>>();
        if (root == null || target <= 0)
            return ans;
        path = new ArrayList<Integer>();
        addPath(root, target, 0);
        return ans;
    }
    private void addPath(TreeNode root, int target, int sum) {
        if (root == null)
            return;
        path.add(root.val);
        if (root.left == null && root.right == null &&
            sum + root.val == target) {
            ArrayList<Integer> temp = new ArrayList<Integer>(path);
            ans.add(temp);
        }
        addPath(root.left, target, sum + root.val);
        addPath(root.right, target, sum + root.val);
        path.remove(path.size() - 1);
    }
}
