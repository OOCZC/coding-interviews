class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
        }
        if(stack2.empty())
            throw std::exception();
        int ans = stack2.top();
        stack2.pop();
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/*

// 模板类写法
template<typename T> 
class CQueue{
public:
    CQueue(void);
    ~CQueue(void);
    
    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
}

template<typename T> 
void CQueue<T>::appendTail(const T& node){

} 

template<typename T>
T CQueue<T>::deleteHead(){

}


*/
