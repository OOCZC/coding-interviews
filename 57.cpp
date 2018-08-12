class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> data, int sum) {
        int i = 0, j = data.size() - 1;
        vector<int> ans;
        while (i < j) {
            if (data[i] + data[j] == sum) {
                ans.push_back(data[i]);
                ans.push_back(data[j]);
                break;
            }
            else if (data[i] + data[j] > sum)
                j --;
            else
                i ++;
        }
        return ans;
    }
};
