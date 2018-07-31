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
/*
// 用STL的红黑树构建大小为k的排序树
vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
    multiset<int, greater<int>> intSet;
    multiset<int, greater<int>>::iterator iter_set = intSet.begin();
    vector<int> ans;
    if(input.size() < k)
        return ans;
    for(int i = 0; i < input.size(); ++i){
        if(intSet.size() < k)
            intSet.insert(input[i]);
        else{
            iter_set = intSet.begin();
            if(*iter_set > input[i]){
                intSet.erase(iter_set);
                intSet.insert(input[i]);
            }
        }
    }
    for(iter_set = intSet.begin(); iter_set != intSet.end(); ++iter_set)
        ans.push_back(*iter_set);
    return ans;
}
*/
