// 删除链表中的所有重复元素，第一遍自己没写出来。
ListNode* deleteDuplication(ListNode* pHead){
    if(pHead == nullptr || pHead -> next == nullptr)
        return pHead;

    ListNode* preNode = nullptr;
    ListNode* Node = pHead;
    ListNode* Next;
    while(Node != nullptr){
        bool isDup = false;
        Next = Node -> next;  // Next 的赋值放到前面来，放在后面容易空指针
        if(Next != nullptr && Node -> val == Next -> val) 
            isDup = true;
        if(isDup){
            int DupVal = Node -> val;
            ListNode* ToBeDel = Node;
            while(ToBeDel != nullptr && ToBeDel -> val == DupVal){
                Node = Node -> next;
                delete ToBeDel;
                ToBeDel = Node;
            }
            if(preNode == nullptr)
                pHead = Node;
            else
                preNode -> next = Node;
            //Next = Node -> next;
        }
        else{
            preNode = Node;
            Node = Next;
            //Next = Next -> next;   这里的Next -> next 很容易出问题
        }
        
    }
    return pHead;
}
