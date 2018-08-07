class Solution{
public:
    bool static cmp(string a, string b){ // 这里需要为static函数
        return a + b < b + a;
    }
    string PrintMinNumber(vector<int> numbers){
        vector<string> strings;
        for(int i = 0; i < numbers.size(); ++i){
            strings.push_back(to_string(numbers[i]));
        }
        sort(strings.begin(), strings.end(), cmp);
        string ans = "";
        for(int i = 0; i < strings.size(); ++i){
            ans += strings[i];
        }
        return ans;
    }

};
