class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        int length1 = 0, length2 = 0;
        ListNode *p1 = pHead1, *p2 = pHead2;
        while(p1 != nullptr){
            p1 = p1 -> next;
            length1 ++;
        }
        while(p2 != nullptr){
            p2 = p2 -> next;
            length2 ++;
        }
        p1 = pHead1, p2 = pHead2;
        if(length1 > length2){
            for(int i = 0; i < length1 - length2; ++i)
                p1 = p1 -> next;
        }
        else{
            for(int i = 0; i < length2 - length1; ++i)
                p2 = p2 -> next;
        }
        while(p1 != p2){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p1;
    }
};
