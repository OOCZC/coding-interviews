#include <stdio.h>

void Qsort(int data[], int start, int end){
    int i = start, j = end;
    if(start >= end)
        return;
    int flag = data[start];
    while(i < j){
        while(data[j] >= flag && i < j){
            j--;
        }
        data[i] = data[j];
        while(data[i] <= flag && i < j){
            i++;
        }
        data[j] = data[i];
    }
    data[i] = flag;
    Qsort(data, start, i - 1);
    Qsort(data, i + 1, end);
}
    
int main(){
    int a[] = {4,56,2,6,56,56,4,4,2,6,99};
    Qsort(a, 0, sizeof(a) / 4 - 1);
    for(int i = 0; i < sizeof(a) / 4; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}
