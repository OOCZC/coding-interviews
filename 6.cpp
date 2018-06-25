/*
    struct ListNode{
        int val;
        struct ListNode *next;
        ListNode(int x):
            val(x), next(NULL){}
    }
*/

// 倒序打印链表
vector<int> printListFromTailToHead(ListNode* head){
    std::stack<int> list;
    std::vector<int> ans;
    while(head != NULL){
        list.push(head -> val);
        head = head -> next;
    }
    while(!list.empty()){
        ans.push_back(list.top());
        list.pop();
    }
    return ans;
}


// 递归形式
void printListFromTailToHead(ListNode* head){
    if(head -> next == NULL){
        printf("%d ", head -> val);
        return;
    }
    printListFromTailToHead(head -> next);
    printf("%d ", head -> val);
    return;
}

// 结尾增加节点
void addNode(ListNode*& head, int val){
    ListNode* node = new ListNode(val);
    ListNode* p;
    if(head == nullptr){
        head = node;
        return;
    }
    p = head;
    while(p -> next != nullptr){
        p = p -> next;
    }
    p -> next = node;
    return;
}
