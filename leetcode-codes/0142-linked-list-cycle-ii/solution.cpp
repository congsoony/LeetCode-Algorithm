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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *,int> check;
        while(head){
            if(check[head])return head;
            check[head]=1;
            head=head->next;
        }
        return 0;
    }
};
