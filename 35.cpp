RandomListNode* Clone(RandomListNode *Head){
    if(Head == nullptr)
        return nullptr;
    RandomListNode *newHead = new RandomListNode(Head -> label);
    RandomListNode *p = Head, *newp = newHead, *q = p -> next, *newq = newp -> next;
    unordered_map<RandomListNode*, RandomListNode*> m;
    m[Head] = newHead;
    while(q != nullptr){
        newq = new RandomListNode(q -> label);
        newp -> next = newq;
        newq = newq -> next;
        newp = newp -> next;
        q = q -> next;
        p = p -> next;
        m[p] = newp;
    }
    p = Head, newp = newHead;
    while(p != nullptr){
        newp -> random = m[p -> random];
        p = p -> next;
        newp = newp -> next;
    }
    return newHead;
}
