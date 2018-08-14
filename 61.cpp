class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.size() == 0)
            return false;
        sort(numbers.begin(), numbers.end());
        int numberOf0 = 0, i = 0;
        while (i < numbers.size() && numbers[i] == 0) {
            ++ i;
            ++ numberOf0;
        }
        for (i = i + 1; i < numbers.size(); ++i) {
            numberOf0 -= numbers[i] - numbers[i - 1] - 1;
            if (numberOf0 < 0 || numbers[i] == numbers[i - 1])
                return false;
        }
        return true;
    }
};
