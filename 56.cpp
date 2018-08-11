class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
        int sum = 0, i, bit_i;
        for (i = 0; i < data.size(); ++i) {
            sum ^= data[i];
        }
        for (bit_i = 0; bit_i < 32 ; ++bit_i) 
            if ((sum >> bit_i & 1) == 1)
                break;
        if (bit_i == 32)
            return;
        vector<int> data1, data2;
        for (i = 0; i < data.size(); ++i) {
            if ((data[i] >> bit_i & 1) == 1)
                data1.push_back(data[i]);
            else
                data2.push_back(data[i]);
        }
        sum = 0;
        for (i = 0; i < data1.size(); ++i) {
            sum ^= data1[i];
        }
        *num1 = sum;
        sum = 0;
        for (i = 0; i < data2.size(); ++i) {
            sum ^= data2[i];
        }
        *num2 = sum;
    }
};

/*
int main() {
    Solution a;
    int int_data[] = {2,2,1,3};
    vector<int> data;
    for (int i = 0; i < sizeof(int_data) / 4; ++i)
        data.push_back(int_data[i]);
    int num1 = 0, num2 = 0;
    int *p1 = &num1, *p2 = &num2;
    a.FindNumsAppearOnce(data, p1, p2);
    cout << *p1 << " " << *p2 << endl;
    return 0;
}
*/
