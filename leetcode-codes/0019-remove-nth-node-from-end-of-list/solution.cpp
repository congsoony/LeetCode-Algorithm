/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<int> v;
		while (head){
			v.push_back(head->val);
			head = head->next;
		}
		ListNode *list = NULL,*tail;
		for (int i = 0; i < v.size(); i++){
			if (i == v.size() - n)
				continue;
			if (list == NULL){
				list = new ListNode(v[i]);
				tail = list;
			}
			else{
				tail->next = new ListNode(v[i]);
				tail = tail->next;
			}
		}
		return list;
	}
};
