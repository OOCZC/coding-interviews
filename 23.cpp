/*
#include <stdio.h>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};
ListNode* FindLoopNode(ListNode* pHead);
*/

// 返回入口节点
ListNode* EntryNodeOfLoop(ListNode* pHead){
    ListNode* loopNode = FindLoopNode(pHead); // 返回环内一节点
    if(loopNode == nullptr) // 无环
        return nullptr;
    ListNode* p = loopNode -> next;
    int loopNum = 1; // 循环体内节点的个数
    while(p != loopNode){
        loopNum ++;
        p = p -> next;
    }

    ListNode* behind = pHead, *ahead = pHead;
    while(-- loopNum){
        ahead = ahead -> next;
    }
    while(ahead -> next != behind){ // ?
        ahead = ahead -> next;
        behind = behind -> next;
    }
    return behind;
}

// 返回loop中的某个节点，不存在loop返回nullptr
ListNode* FindLoopNode(ListNode* pHead){
    if(pHead == nullptr)
        return nullptr;
    ListNode *oneStep = pHead, *twoStep = pHead -> next;
    while(twoStep != nullptr && twoStep -> next != nullptr 
          && oneStep != twoStep){
        twoStep = twoStep -> next;
        twoStep = twoStep -> next;
        oneStep = oneStep -> next;
    }
    if(twoStep == nullptr || twoStep -> next == nullptr)
        return nullptr;
    return oneStep;
}

/*
int main(){
    ListNode* list[5];
    for(int i = 0; i < 5; ++i){
        list[i] = new ListNode(i + 1);
    }
    for(int i = 0; i < 4; ++i){
        list[i] -> next = list[i + 1];
    }
    
    list[4] -> next = list[1];
    ListNode* ans = EntryNodeOfLoop(list[0]);
    printf("%d \n", ans -> val); // 2
    return 0;
}
*/
