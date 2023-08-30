/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int getlen(ListNode* cur){
    int cnt =0;
    while(cur){
        cur=cur->next;
        cnt++;
    }
    return cnt;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode * cur1=headA;
    ListNode * cur2=headB;
    int len1=getlen(cur1),len2=getlen(cur2);
    while(len1!=len2){
        if(len1>len2){
            cur1=cur1->next;
            len1--;
        }else{
            cur2=cur2->next;
            len2--;
        }
    }
    while(cur1&&cur2){
        if(cur1==cur2)return cur1;
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return nullptr;
}
};
