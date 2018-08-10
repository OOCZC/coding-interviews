// Partition method
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

// heap method
class Solution{
public:
    void AdjustHeap(vector<int>& nums, int i, int n){
        // nums[0] 是堆顶，堆中共有n个元素，现在调整 i
        int root = i, j = root * 2 + 1;
        while(j < n){
            if(j + 1 < n && nums[j + 1] > nums[j]) // 对比左右子节点的大小
                j++;
            if(nums[root] < nums[j]){
                swap(nums[root], nums[j]);
                root = j;
                j = root * 2 + 1;
            }
            else
                break;
        }
    }
    int findKthLargest(vector<int>& nums, int k){
        if(k > nums.size())
            return 0;
        // 初始化大顶堆
        for(int i = nums.size() / 2 - 1; i >= 0; --i) // 从 n/2-1 开始
            AdjustHeap(nums, i, nums.size());
        // 对k-1个元素出堆
        for(int i = 0; i < k - 1; ++i){
            nums[0] = nums[nums.size() - 1 - i]; // 把堆中最后一个元素移到堆顶
            AdjustHeap(nums, 0, nums.size() - i);
        }
        return nums[0];
    }
};
