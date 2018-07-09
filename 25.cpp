// 合并俩递增链表为一个递增链表
ListNode* Merge(ListNode *pHead1, ListNode *pHead2){
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;
    ListNode *MergeHead, *MergeTail;
    if(pHead1 -> val >= pHead2 -> val){
        MergeHead = pHead2;
        MergeTail = pHead2;
        pHead2 = pHead2 -> next;
        MergeTail -> next = nullptr;
    }
    else{
        MergeHead = pHead1;
        MergeTail = pHead1;
        pHead1 = pHead1 -> next;
        MergeTail -> next = nullptr;
    }
    while(pHead1 != nullptr && pHead2 != nullptr){
        if(pHead1 -> val >= pHead2 -> val){
            MergeTail -> next = pHead2;
            MergeTail = MergeTail -> next;
            pHead2 = pHead2 -> next;
            MergeTail -> next = nullptr;
        }
        else{
            MergeTail -> next = pHead1;
            MergeTail = MergeTail -> next;
            pHead1 = pHead1 -> next;
            MergeTail -> next = nullptr;
        }
    }
    if(pHead1 != nullptr){
        MergeTail -> next = pHead1;
    }
    if(pHead2 != nullptr){
        MergeTail -> next = pHead2;
    }
    return MergeHead;        
}

// 递归实现
ListNode* Merge(ListNode *pHead1, ListNode *pHead2){
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;
    if(pHead1 -> val >= pHead2 -> val){
        pHead2 -> next = Merge(pHead1, pHead2 -> next);
        return pHead2;
    }
    else{
        pHead1 -> next = Merge(pHead1 -> next, pHead2);
        return pHead1;
    }
}
