class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (n > str.size()) {
            string ans;
            return ans;
        }
        char *reStr = new char[str.size() + 1]();
        int i = 0, j = n;
        while (j < str.size()) {
            reStr[i ++] = str[j ++];
        }
        j = 0;
        while (j < n) {
            reStr[i ++] = str[j ++];
        }
        string returnStr(reStr);
        return reStr;
    }
};
