public class Solution {

    public int Fibonacci(int n) {
        int[] num = new int[n + 2];
        num[1] = 1;
        
        for (int i = 1; i < n; ++i) {
            num[i + 1] = num[i] + num[i - 1];
        }
        
        return num[n];
    }
}
