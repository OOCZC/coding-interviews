class Solution
{
public:
    Solution() {
        for (int i = 0; i < 128; ++i) {
            charCount[i] = 0;
        }
    }
  //Insert one char from stringstream

    void Insert(char ch)
    {
        ++ num; 
        if (charCount[ch] == 0) {
            charCount[ch] = num;
        }
        else {
            charCount[ch] = -1;
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int min = INT_MAX, ans = -1;
        for (int i = 0; i < 128; ++i) {
            if (charCount[i] != -1 && charCount[i] != 0
                && charCount[i] < min) {
                ans = i;
                min = charCount[i];
            }
        }
        if (ans == -1)
            return '#';
        else
            return ans;
    }
private:
    int num = 0;
    int charCount[128];
};
