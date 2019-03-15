public class Solution {

    public ListNode deleteDuplication(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode pre = null; // 两个及以上结点
        ListNode node = head;
        ListNode next;
        boolean begin = true;
        
        while (node != null) {
            next = node.next;
            if (next != null && node.val == next.val) {
                while (next != null && node.val == next.val) 
                    next = next.next;
                node = next;
                if (begin)
                    head = node;
                else
                    pre.next = node;
            }
            else {
                pre = node;
                node = node.next;
                begin = false;
            }
        }

        return head;
    }
}
