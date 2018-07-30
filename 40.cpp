vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
    // MinHeap
    vector<int> minNum;
    if(input.size() < k)
        return minNum;
    for(int i = input.size() / 2 - 1; i >= 0; --i){
        AdjustHeap(input, i, input.size());
    }
    for(int i = 0; i < k; ++i){
        minNum.push_back(input[0]);
        input[0] = input[input.size() - i - 1];
        AdjustHeap(input, 0, input.size() - i - 1);
    }
    return minNum;
}

void AdjustHeap(vector<int>& input, int i, int n){
    int root = i, j = root * 2 + 1;
    while(j < n){
        if(j + 1 < n && input[j + 1] < input[j])
            j++;
        if(input[root] > input[j]){
            swap(input[root], input[j]);
            root = j;
            j = root * 2 + 1;
        }
        else
            break;
    }
}
