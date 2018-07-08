/*
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x){
            val = x;
            next = nullptr;
        }
    }
*/


ListNode* FindKthToTail(ListNode* ListHead, unsigned int k){
    if(ListHead == nullptr || k <= 0)
        return nullptr;
    ListNode* behind = nullptr, *ahead = ListHead;
    while(k && ahead != nullptr){
        ahead = ahead -> next;
        -- k;
    }
    if(k != 0)
        return nullptr; // 不足k个节点
    behind = ListHead;
    while(ahead != nullptr){
        ahead = ahead -> next;
        behind = behind -> next;
    }
    return behind;
}
