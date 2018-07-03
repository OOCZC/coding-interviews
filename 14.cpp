#include <memory.h>
#include <stdio.h>

int maxProductAfterCutting(int length){
    if(length <= 1)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int* product = new int[length + 1];
    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3;
    
    for(int i = 4; i <= length; ++i){
        int max = 0;
        for(int j = 1; j <= i / 2; ++j){
            if(product[j] * product[i - j] > max)
                max = product[j] * product[i - j];
        }
        product[i] = max;
    }
    return product[length];
}

/*
int main(){
    printf("%d\n", maxProductAfterCutting(10));
    return 0;
}
*/
