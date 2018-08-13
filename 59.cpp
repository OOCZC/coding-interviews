class Solution {
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        vector<int> maxInWindows;
        if (num.size() < size)
            return maxInWindows;
        deque<int> que;

        for (int i = 0; i < num.size(); ++i) {
            if (que.size() != 0 && i - int(size) >= que[0]) { // 清除过时的数据
                que.pop_front();
            }
            while (que.size() != 0 && num[i] >= num[que[que.size() - 1]]) {
                que.pop_back();
            }
            que.push_back(i);
            if (i >= size - 1)
                maxInWindows.push_back(num[que[0]]);
        }
        return maxInWindows;
    }
};

/*
int main() {
    Solution s;
    int data1[] = {16,14,12,10,8,6,4};
    vector<int> data;
    for (int i = 0; i < sizeof(data1) / 4; ++i) {
        data.push_back(data1[i]);
    }
    vector<int> ans;
    ans = s.maxInWindows(data, 5);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;
    return 0;
}
*/
