/*
    长度为n的数组里的所有数字都在0～n-1的范围内，
    数组中某些数字重复，找出它们中的某个。
    时间复杂度O(n)，空间复杂度O(1)
*/

bool duplicate(int numbers[], int length, int* duplication){
    if(numbers == nullptr || length <= 0){
        return false;
    }
    for(int i = 0; i < length; ++i){
        if(numbers[i] < 0 || numbers[i] >= length)
            return false;
    }

    for(int i = 0; i < length; ++i){
        while(i != numbers[i]){
            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[numbers[i]];
            numbers[numbers[i]] = temp;
        }
    }
    return false;
}
