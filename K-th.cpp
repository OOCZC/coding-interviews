class Solution{
public:
    int findKthLargest(vector<int>& nums, int k){
        if(k > nums.size())
            return 0;
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }

    int findKthLargest(vector<int>& nums, int begin, int end, int k){
        if(nums.size() <= 0 || k < 1 || begin > end)
            return 0;
        int flag = nums[begin], i = begin, j = end;
        while(i < j){
            while(nums[j] >= flag && i < j)  // 大的放右边
                j--;
            nums[i] = nums[j];
            while(nums[i] < flag && i < j)
                i++;
            nums[j] = nums[i];
        }
        nums[i] =  flag;
        if(nums.size() - i == k)
            return nums[i];
        else if(nums.size() - i < k) // 留左边
            return findKthLargest(nums, begin, i - 1, k);
        else  // 留右边
            return findKthLargest(nums, i + 1, end, k);
    }
};
