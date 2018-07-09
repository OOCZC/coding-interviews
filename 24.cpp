ListNode* ReverseList(ListNode* pHead){
    if(pHead == nullptr || pHead -> next == nullptr)
        return pHead;
    ListNode *ahead = pHead -> next, *behind = pHead;
    ListNode *temp;
    pHead -> next = nullptr;
    while(ahead != nullptr){
        temp = ahead -> next;
        ahead -> next = behind;
        behind = ahead;
        ahead = temp;
    }
    return behind;
}
