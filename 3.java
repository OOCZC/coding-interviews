public class Solution {

    public boolean duplicate(int numbers[], int length, int duplication[]) {

        if (length <= 0 || numbers == null)
            return false;
        
        for (int i = 0; i < length; ++i) {
            if (numbers[i] < 0 || numbers[i] >= length)
                return false;
        }
        
        for (int i = 0; i < length; ++i) {
            while (i != numbers[i]) {
                if (numbers[i] == numbers[numbers[i]]) {
                    duplication[0] = numbers[i];
                    return true;
                }
      
                swap(numbers, i, numbers[i]);
            }
        }

        return false;
    }

    private void swap(int[] num, int i, int j) {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
}
