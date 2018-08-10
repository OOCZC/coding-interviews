class Solution{
public:
    int InversePairs(vector<int> data){
        vector<int> copy(data);
        return InversePairs(data, copy, 0, data.size() - 1);
    }
    int InversePairs(vector<int> &data, vector<int> &copy,
                      int start, int end){
        if(start == end)
            return 0;
        int middle = (start + end) >> 1;
        int left = InversePairs(copy, data, start, middle);
        int right = InversePairs(copy, data, middle + 1, end);
        int count = 0, i = middle, j = end, copyIndex = end;
        while(i >= start && j >= middle + 1){
            if(data[i] > data[j]){
                copy[copyIndex--] = data[i--];
                count += j - middle;
            }
            else{
                copy[copyIndex--] = data[j--];
            }
        }
        while(i >= start)
            copy[copyIndex--] = data[i--];
        while(j >= middle + 1)
            copy[copyIndex--] = data[j--];
        return left + right + count;
    }
};

/*
int main(){
    Solution a;
    int int_data[] ={ 1, 2, 1, 2, 1 };
    vector<int> data(int_data, int_data+5);
    cout << a.InversePairs(data) << endl;
    return 0;
}
*/
