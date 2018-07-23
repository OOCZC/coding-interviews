class Solution {
public:
    stack<int> data;
    stack<int> data_min;
public:
    void push(int value) {
        data.push(value);
        if(data_min.size() == 0)
            data_min.push(value);
        else if(value > data_min.top())
            data_min.push(data_min.top());
        else
            data_min.push(value);
    }
    void pop() {
        data.pop();
        data_min.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return data_min.top();
    }
};
