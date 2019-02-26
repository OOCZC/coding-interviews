public class Solution {
    public boolean Find(int target, int[][] array) {
        if (array == null || array.length == 0 || array[0].length == 0)
            return false;
        int col = array[0].length - 1;
        int row = 0;
        while (row < array.length && col >= 0) {
            if (array[row][col] == target)
                return true;
            if (array[row][col] < target)
                row ++;
            else
                col --;
        }
        return false;
    }
}
