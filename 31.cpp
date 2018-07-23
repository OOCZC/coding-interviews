bool IsPopOrder(vector<int> pushV, vector<int> popV){
    if(pushV.size() != popV.size())
        return false;
    int length = pushV.size();
    int i = 0, j = 0;
    stack<int> stack;
    while(i < length || j < length){
        if(stack.size() != 0){
            if(stack.top() == popV[j]){
                stack.pop();
                ++j;
                continue;
            }
            else if(i >= length){
                return false;
            }
            else{
                stack.push(pushV[i++]);
            }
        }
        else{
            stack.push(pushV[i++]);
        }
    }
    return true;
}
