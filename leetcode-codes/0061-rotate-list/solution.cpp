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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
        ListNode *cur = head;
        ListNode *tail = cur;
        while(cur){
            size++;
            tail=cur;
            cur=cur->next;
        }
        if(size==0)return head;
        k %=size;
        k = size-k;
        while(k--){
            ListNode *newnode = new ListNode(head->val);
            tail->next=newnode;
            tail=tail->next;
            ListNode * del =head;
            head=head->next;
            delete del;
        }
        return head;
    }
};
