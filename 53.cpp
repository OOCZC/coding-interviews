class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.size() == 0)
            return 0;
        int firstPos = GetFirstOfK(data, k);
        int lastPos = GetLastOfK(data, k);
        if (firstPos == -1) // 不存在是返回 -1
            return 0;
        return lastPos - firstPos + 1;
    }

    int GetFirstOfK(vector<int> data, int k) {
        int i = 0, j = data.size() - 1;
        while (i < j) {
            int middle = (i + j) >> 1;
            if (data[middle] < k)
                i = middle + 1;
            else if (data[middle] > k)   
                j = middle - 1;
            else
                j = middle;
        }
        if (data[i] != k)
            return -1;
        return i;  // 这里return j 不行
    }
// 二分时考虑的情况就是i == j - 1 与 i == j - 2 两种情况。
    int GetLastOfK(vector<int> data, int k) {
        int i = 0, j = data.size() - 1;
        while (i < j) {
            int middle = (i + j) >> 1;
            if ((i + j) % 2 == 1)  //  向后挤压, 比如i = 2, j = 3, middle为3。
                middle ++;         //  此处如果向前挤压，最后的 i = middle 处有bug。
            if (data[middle] < k)
                i = middle + 1;
            else if (data[middle] > k)   
                j = middle - 1;
            else
                i = middle;
        }
        if (data[i] != k)
            return -1;
        return i;
    }
};
