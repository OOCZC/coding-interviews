#include <iostream>
using namespace std;

// 虚函数求解
class A {
public:
    virtual int getSum(int n) {
        return 0;
    }
};

A *a[2]; // 这里必须声明在外面，声明在类内段错误。因为新Solution对象的a[]还没赋值

class Solution:A {
public:
    virtual int getSum(int n) {
        return a[!!n] -> getSum(n - 1) + n;
    }
    int Sum_Solution(int n) {
        a[0] = new A();
        a[1] = new Solution();
        int ans = a[!!n] -> getSum(n);
        delete a[0];
        delete a[1];
        return ans;
    }
};

/*
int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.Sum_Solution(n) << endl;
    return 0;
}
*/
