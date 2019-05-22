public class Solution {

    public ListNode EntryNodeOfLoop(ListNode pHead) {
        if (pHead == null)
            return null;
        ListNode fast = pHead.next, slow = pHead;
        while(fast != null && slow != null) {
            if (fast == slow) {
                int count = countLoop(fast);
                return getEntry(pHead, count);
            }
            slow = slow.next;
            fast = fast.next;
            if (fast != null)
                fast = fast.next;
        }
        return null;
    }
  
    private ListNode getEntry(ListNode pHead, int count) {
        ListNode first = pHead, second = pHead;
        while (count != 0) {
            count --;
            first = first.next;
        }
        while (second != first) {
            second = second.next;
            first = first.next;
        }
        return first;
    }
    
    private int countLoop(ListNode node) {
        ListNode i = node.next;
        int count = 1;
        while (i != node) {
            count++;
            i = i.next;
        }
        return count;
    }
}
