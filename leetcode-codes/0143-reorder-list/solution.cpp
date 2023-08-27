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
void reorderList(ListNode* head) {
        if(!head)return;

        deque<int> dq;
        ListNode * cur = head->next;
        while(cur){
            ListNode * del = cur;
            dq.push_back(cur->val);
            cur=cur->next;
            delete del;
        }
        cur=head;
        int idx =1;
        while(!dq.empty()){
            if(idx%2){
                cur->next=new ListNode(dq.back());
                dq.pop_back();
            }
            else{
                cur->next= new ListNode(dq.front());
                dq.pop_front();
            }
            cur=cur->next;
            idx++;
        }
    }
};
