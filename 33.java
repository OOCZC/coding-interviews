class Solution {
    public boolean VerifySquenceOfBST(int[] seq) {
        if (seq == null || seq.length <= 0) {
            return false;
        }
 
        return VerifySquenceOfBST(seq, 0, seq.length -1);
    }
 
    private boolean VerifySquenceOfBST(int[] seq, int start, int end) {
        if (end <= start)
            return true;
        int root = seq[end];
        int mid = -1, i = start;
        boolean flag = true;
        for (; i < end; ++ i) {
            if (seq[i] < root) {
                mid = i;
                continue;
            }
            else if(seq[i] == root) {
                return false;
            }
            else {
                mid = i;
                break;
            }
        }
        for (; i < end; ++ i) {
            if (seq[i] <= root)
                return false;
        }
        if (i != end) {
            return false;
        }
 
        return VerifySquenceOfBST(seq, start, mid - 1) && VerifySquenceOfBST(seq, mid, end - 1);
    }
}
