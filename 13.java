public class Solution {
   
    private int count = 0;
    private boolean[][] flag;

    public int movingCount(int threhold, int rows, int cols) {
        flag = new boolean[rows][cols];
        count = 0;
        Dfs(threhold, 0, 0, rows, cols);
        return count;
    }
    
    private void Dfs(int threhold, int row, int col, int rows, int cols) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || flag[row][col])
            return;

        if (digitMatch(threhold, row, col)) {
            count ++;
            flag[row][col] = true;
            Dfs(threhold, row + 1, col, rows, cols);
            Dfs(threhold, row - 1, col, rows, cols);
            Dfs(threhold, row, col + 1, rows, cols);
            Dfs(threhold, row, col - 1, rows, cols);
        }
    }
   
    private boolean digitMatch(int threhold, int row, int col) {
        return threhold >= digitSum(row) + digitSum(col);
    }

    private int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
}
