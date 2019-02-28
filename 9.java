public class Solution {

    private Stack<Integer> stackPush = new Stack<Integer>();
    private Stack<Integer> stackPop = new Stack<Integer>();

    public void push(int node) {
        stackPush.push(node);
    }

    public int pop() {
        if (stackPop.size() == 0) {
            while (!stackPush.empty())
                stackPop.push(stackPush.pop());
        }
        
        return stackPop.pop();
    }
}
