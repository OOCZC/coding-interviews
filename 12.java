import java.util.Arrays;

public class Solution {
    
    boolean[] matrix_flag;

    public boolean hasPath(char[] matrix, int rows, int cols, char[] str) {
        if (matrix == null || str == null)
            return false;

        matrix_flag = new boolean[rows * cols];
        for (int i = 0; i < rows * cols; ++i) {
            Arrays.fill(matrix_flag, false);
            if (hasPathCore(matrix, rows, cols, str, 0, i / cols, i % cols))
                return true;
        }
        return false;
    }
     
    private boolean hasPathCore
           (char[] matrix, int rows, int cols, char[] str,
            int curr_str_num, int curr_row, int curr_col) {

        if (curr_str_num == str.length)
            return true;
        if (curr_row >= rows || curr_col >= cols || curr_row < 0 || curr_col < 0)
            return false;
        if (matrix_flag[curr_row * cols + curr_col])
            return false;

        matrix_flag[curr_row * cols + curr_col] = true;

        if (str[curr_str_num] == matrix[curr_row * cols + curr_col]) {
            return hasPathCore(matrix, rows, cols, str, curr_str_num + 1, curr_row + 1, curr_col) ||
            hasPathCore(matrix, rows, cols, str, curr_str_num + 1, curr_row - 1, curr_col) ||
            hasPathCore(matrix, rows, cols, str, curr_str_num + 1, curr_row, curr_col + 1) ||
            hasPathCore(matrix, rows, cols, str, curr_str_num + 1, curr_row, curr_col - 1);
        }

        matrix_flag[curr_row * cols + curr_col] = false;
        
        return false;
    }
}
