// O(1) 删除链表节点
/*
    struct ListNode{ 
        int val;
        ListNode* next;
    };
*/
void DeleteNode(ListNode*& ListHead, ListNode* ToBeDeleted){
    if(ListHead == nullptr || ToBeDeleted == nullptr)
        return;
    if(ListHead -> next == nullptr){ // 只有一个节点
        ListNode == nullptr;
        delete ToBeDeleted;
        return;
    }
    if(ToBeDeleted -> next != nullptr){  //  如果删除的节点后还有节点
        ListNode* pNext = ToBeDeleted -> next;
        ToBeDeleted -> val = pNext -> val;
        ToBeDeleted -> next = pNext -> next;
        delete pNext;
        return;
    }
    // 删除的节点为尾节点
    ListNode* p = ListHead;
    while(p -> next != ToBeDeleted)
        p = p -> next;
    delete ToBeDeleted;
    p -> next = nullptr;
    return;
}
