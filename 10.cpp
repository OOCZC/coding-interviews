// 斐波那契数列 (非递归实现)
long long Fibonacci(unsigned n){
    long long a = 0, b = 1;
    int num = 1;
    if(n == 0)
        return a;
    else if(n == 1)
        return b;
    else{
        while(num < n){
            int temp = b;
            b = a + b;
            a = temp;
            num ++;
        }
        return b;
    }
}
