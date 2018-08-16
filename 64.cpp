// 构造函数求解

class Solution {
public:
    Solution() {
        N ++;
        Sum += N;
    }
    int Sum_Solution(int n) {
        clear();
        Solution *p = new Solution[n]();
        int ans = getSum();
        delete[] p;
        return ans;
    }
    void clear() {
        N = 0;
        Sum = 0;
    }
    int getSum() {
        return Sum;
    }
private:
    static int N;
    static int Sum;
};

int Solution::N = 0;  // 类静态变量 需在类外定义
int Solution::Sum = 0;

/*
int main() {
    Solution a;
    cout << a.Sum_Solution(3) << endl;
    cout << a.Sum_Solution(2) << endl;
    cout << a.Sum_Solution(1) << endl;
    return 0;
}
*/
