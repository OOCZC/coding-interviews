/*
    长度为n+1的数组里的所有数字都在0～n的范围内，
    数组中某些数字重复，找出它们中的某个。
    时间复杂度O(n)，空间复杂度O(1)
*/

int getDuplication(const int* numbers, int length){
    if(numbers == nullptr || length <= 0)
        return -1;

    int start = 1, end = length - 1;
    while(end >= start){
        int middle = (start + end) / 2;
        //int middle = (end - start) >> 1 + start;
        int num = countRange(numbers, length, start, middle);
        if(end == start){
            if(num > 1)
                return end;
            else
                return -1;
        }
        if(middle - start + 1 < num){
            end = middle;
        }
        else{
            start = middle + 1;
        }
    }
    return -1;
}

// 找出numbers数组中范围在start和end中的元素的个数。
int countRange(const int* numbers, int length, int start, int end){
    if(numbers == nullptr)
        return 0;

    int num = 0;
    for(int i = 0; i < length; ++i){
        if(numbers[i] >= start && numbers[i] <= end)
            num ++;
    } 
    return num;
}

