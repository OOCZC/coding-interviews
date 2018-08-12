class Solution {
public:
    string ReverseSentence(string str) {
        char *reStr = new char[str.size() + 1]();
        int reStrPos = 0;
        for (int i = str.size() - 1; i >= 0;) {
            if (str[i] == ' ') {
                reStr[reStrPos ++] = ' ';
                -- i;
            }
            else {
                int length = 0;
                while (i >= 0 && str[i] != ' ') {
                    length ++;
                    i --;
                }
                int j = i + 1;
                while (length --) {
                    reStr[reStrPos ++] = str[j ++];
                }
            }
        }
        string returnStr(reStr);
        return returnStr;
    }
};
