class Solution{
public:
    void Insert(int num){
        if(maxAVL.size() == minAVL.size()){
            if(num <= *maxAVL.begin())
                maxAVL.insert(num);
            else
                minAVL.insert(num);
        }
        else if(maxAVL.size() > minAVL.size()){
            if(num < *maxAVL.begin()){
                maxAVL.insert(num);
                minAVL.insert(*maxAVL.begin());
                maxAVL.erase(maxAVL.begin());
            }
            else
                minAVL.insert(num);
        }
        else{
            if(num <= *minAVL.begin()){
                maxAVL.insert(num);
            }
            else{
                minAVL.insert(num);
                maxAVL.insert(*minAVL.begin());
                minAVL.erase(*minAVL.begin());
            }
        }
    }

    double GetMedian(){
        multiset<int, greater<int>>::const_iterator max_iter = maxAVL.begin();
        multiset<int, less<int>>::const_iterator min_iter = minAVL.begin();
       
        if(maxAVL.size() == minAVL.size())
            return (*max_iter + *min_iter) * 1.0 / 2;
        else if(maxAVL.size() == minAVL.size() + 1)
            return *max_iter;
        else if(maxAVL.size() == minAVL.size() - 1)
            return *min_iter;
        else
            return 0;
    }

private:
    multiset<int, greater<int>> maxAVL; // 第一个是左边最大的。
    multiset<int, less<int>> minAVL; // 第一个是右边最小的。
};
