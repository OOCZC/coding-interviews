class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array){
        int *dp = new int[array.size()];
        memset(dp, 0, array.size() * sizeof(int));
        dp[0] = array[0];
        for(int i = 1; i < array.size(); ++i){
            dp[i] = max(dp[i - 1] + array[i], array[i]);
        }
        int max = -9999999999;
        for(int i = 0; i < array.size(); ++i){
            if(dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};
