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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *list = new ListNode();
		ListNode *tail=list;
		vector<int> v1, v2;

		pushAllData(v1, l1);
		pushAllData(v2, l2);
		
		int left = 0, right = 0;
		while (left < v1.size() && right < v2.size()){
			if (v1[left] < v2[right])
				tail->next = new ListNode(v1[left++]);
			else
				tail->next = new ListNode(v2[right++]);
			tail = tail->next;
		}
		if (left < v1.size()){
			while (left < v1.size()){
				tail->next = new ListNode(v1[left++]);
				tail = tail->next;
			}
		}
		else{
			while (right < v2.size()){
				tail->next = new ListNode(v2[right++]);
				tail = tail->next;
			}
		}
		tail = list;
		list = list->next;
		delete tail;
		return list;
	}

	void pushAllData(vector<int> &v,ListNode *list){
		while (list){
			v.push_back(list->val);
			list = list->next;
		}
		
	}
};
