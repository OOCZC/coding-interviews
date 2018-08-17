// 函数指针求解

typedef int (*fun)(int n);
fun f[2];

int Sum_1(int n) {
    return 0;
}
int Sum_2(int n) {
    return f[!!n](n - 1) + n;
}
class Solution {
public:
    int Sum_Solution(int n) {
        f[0] = Sum_1;
        f[1] = Sum_2;
        return f[!!n](n - 1) + n;
    }
};

/*
int main() {
    Solution s;
    cout << s.Sum_Solution(3) << endl;
    return 0;
}
*/
