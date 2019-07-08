// partition , no sort
 
import java.util.ArrayList;
 
public class Solution {
    // least K
    public ArrayList<Integer> GetLeastNumbers_Solution(int[] input, int k) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if (input == null || k <= 0 || k > input.length) {
            return ans;
        }
        findKleast(input, k - 1);
        for (int i = 0; i < k; ++ i)
            ans.add(input[i]);
        return ans;
    }
    // k == 2
    private void findKleast(int[] input, int k) {
        int left = 0, right = input.length - 1;
        int mid = findMid(input, 0, input.length - 1);
        while(mid != k) {
//            System.out.println(mid);
            if (mid < k) {
                left = mid + 1;
                mid = findMid(input, left, right);
            }
            else {
                right = mid - 1;
                mid = findMid(input, left, right);
            }
        }
    }
 
    private int findMid(int[] input, int left, int right) {
        int root = input[right];
        while (left < right) {
            while (input[left] <= root && left < right) {
                left ++;
            }
            input[right] = input[left];
            while (input[right] > root && left < right) {
                right --;
            }
            input[left] = input[right];
        }
        input[left] = root;
        return left;
    }
 
    public static void main(String[] args) {
        int[] input = {1,5,2,7,9,3,33,90};
        ArrayList<Integer> ans = new Solution().GetLeastNumbers_Solution(input, 3);
        for (Integer i : ans)
            System.out.println(i);
    }
}
