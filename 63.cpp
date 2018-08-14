int INT_MAX = 99999999;

int MaxProfit(vector<int> nums) {
    int min = INT_MAX, maxPro = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < min)
            min = nums[i];
        if (nums[i] - min > maxPro)
            maxPro = nums[i] - min;
    }
    return maxPro;
}

/*
int main() {
    int value[] ={ 4, 2 };
    vector<int> value_vec;
    for (int i = 0; i < sizeof(value) / 4; ++ i) {
        value_vec.push_back(value[i]);
    }
    cout << MaxProfit(value_vec) << endl;
    return 0;
}
*/
