import java.util.ArrayList;

public class Solution {

    public ArrayList<Integer> printListFromTailToHead(ListNode head) {

        ArrayList<Integer> arr = new ArrayList<Integer>();

        if (head == null) {
            return arr;
        }

        ListNode p = head;

        for (; p != null; p = p.next) {
            arr.add(p.val);
        }
       
        for (int i = 0; i < arr.size() / 2; ++i) {
            int temp = arr.get(i);
            arr.set(i, arr.get(arr.size() - i - 1));
            arr.set(arr.size() - i - 1, temp);
        }

        return arr;
    }
}

/*  使用栈

public class Solution {

    public ArrayList<Integer> printListFromTailToHead(ListNode head) {

        ArrayList<Integer> arr = new ArrayList<Integer>();
        Stack<Integer> stack = new Stack<Integer>();

        if (head == null) {
            return arr;
        }

        ListNode p = head;

        for (; p != null; p = p.next) {
            stack.push(p.val);
        }
       
        while (!stack.empty()) {
            arr.add(stack.pop());
        }

        return arr;
    }
}


*/

/*  使用递归

public class Solution {
    
    ArrayList<Integer> arr = new ArrayList<Integer>();

    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {

        if (listNode != null) {
            printListFromTailToHead(listNode.next);
            arr.add(listNode.val);
        }

        return arr;
    }
}


*/
