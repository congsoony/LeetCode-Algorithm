/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head){
        if(!head) return nullptr; 
        ListNode *newhead = new ListNode(head->val);
        ListNode * cur=newhead;
        head=head->next;
        while(head){
            cur->next=new ListNode(head->val);
            cur=cur->next;
            head=head->next;
        }
        cur = newhead;
        while(cur){
            if(cur->next){
                swap(cur->val,cur->next->val);
                cur=cur->next;
            }
            cur=cur->next;
        }

        return newhead;
    }
};
