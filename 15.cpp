#include <stdio.h>

int NumberOf1(int n){
    int flag = 1
    int ans = 0; 
    while(flag){ //  左移最后变为0
        if(flag & n)
            ans ++;
        flag = flag << 1;
    }
    return ans;
}

/*
int main(){
    printf("%d\n", NumberOf1(0));
    printf("%d\n", NumberOf1(1));
    printf("%d\n", NumberOf1(10));
    printf("%d\n", NumberOf1(0x7FFFFFFF));
    printf("%d\n", NumberOf1(0xFFFFFFFF));
    printf("%d\n", NumberOf1(0x80000000));
    return 0;
}
*/
