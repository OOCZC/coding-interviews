class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        int left = 0, right = 2; // 从0开始
        int *dataSum = new int[sum / 2 + 2]();
        vector<vector<int>> ans;
        for (int i = 1; i <= sum / 2 + 1; ++i) {
            dataSum[i] = dataSum[i - 1] + i;
        }
        // dataSum 数组的目的是计算一段序列的值，这里每次移动一个位置，用一个值保存，时时更新也可。
        while (left < right - 1 && right <= sum / 2 + 1) {
            if (dataSum[right] - dataSum[left] == sum) {
                vector<int> seq;
                for (int i = left + 1; i <= right; ++i) {
                    seq.push_back(i);
                }
                ans.push_back(seq);
                right ++; // 加入后，记得 ++
            }
            else if (dataSum[right] - dataSum[left] > sum) {
                left ++;
            }
            else {
                right ++;
            }
        }
        delete[] dataSum;
        return ans;
    }
};
