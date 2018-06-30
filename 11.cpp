// 非递减数组，旋转后，寻找最小元素，O(logn)

int orderMin(vector<int> array, int start, int end){
    int min = array[start];
    for(int i = start; i <= end; ++i){
        if(array[i] < min)
            min = array[i];
    }
    return min;
}

int Min(vector<int> array){
    int i = 0, j = array.size() - 1;
    int mid = 0; // 防止旋转0个，顺序递增的情况。
    while(array[mid] >= array[j]){
        mid = (i + j) / 2;
        if(i == j - 1)
            return array[j];
        if(array[mid] == array[i] &&
           array[mid] == array[j])
            return orderMin(array, i, j);
        if(array[mid] >= array[i])
            i = mid;
        else if(array[mid] <= array[j])
            j = mid;
    }
    return array[mid];
}

