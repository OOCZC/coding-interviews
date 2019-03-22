public class Solution {

    public ListNode FindKthToTail(ListNode head, int k) {
        if (head == null || k < 1)
            return null;
        
        ListNode node = head, pre = head;
        while (node != null && k > 0) {
            node = node.next;
            -- k;
        }
        if (k > 0)
            return null;
        while (node != null) {
            pre = pre.next;
            node = node.next;
        }
        return pre;
    }
}
