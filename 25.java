public class Solution {

    public ListNode Merge(ListNode p1, ListNode p2) {
        if (p1 == null && p2 == null)
            return null;
        if (p1 == null)
            return p2;
        if (p2 == null)
            return p1;
        
        ListNode temp;
        if (p1.val > p2.val) {
            temp = p2.next;
            p2.next = Merge(p1, temp);
            return p2;
        }
        else {
            temp = p1.next;
            p1.next = Merge(temp, p2);
            return p1;
        }
    }
}
