// Hash 解法，时间复杂度O(N)，空间复杂度O(N)
int MoreThanHalfNum(vector<int> numbers){
    unordered_map<int, int> map;
    for(int i = 0; i < numbers.size(); ++i){
        if(map.count(numbers[i]) == 0)
            map[numbers[i]] = 1;
        else
            map[numbers[i]] += 1;
    }
    unordered_map<int, int>::iterator it;
    for(it = map.begin(); it != map.end(); ++it){
        if(it -> second > numbers.size() / 2.0)
            return it -> first;
    }
    return 0;
}
