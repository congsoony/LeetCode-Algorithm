class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode *ans = nullptr, *tail = nullptr;

		vector<int> v1, v2,sumv,bigv;
		pushAllData(v1, l1);
		pushAllData(v2, l2);
		sumv.resize(max(v1.size(), v2.size())+1, 0);
		int idx = 0;
		for (int i = 0; i < v1.size() && i < v2.size(); i++){
			sumv[i] += v1[i] + v2[i];
			sumv[i + 1] += sumv[i] / 10;
			sumv[i] %= 10;
			idx++;
		}
		bigv = v1.size()>v2.size() ? v1 : v2;
		
		for (int i = idx; i < bigv.size(); i++){
			sumv[i] += bigv[i];
			sumv[i + 1] = sumv[i] / 10;
			sumv[i] %= 10;
		}
		if (sumv.back() == 0)
			sumv.pop_back();
		for (int i = 0; i < sumv.size(); i++){
			if (i == 0){
				ans = new ListNode(sumv[i]);
				tail = ans;
			}
			else{
				tail->next = new ListNode(sumv[i]);
				tail = tail->next;
			}
		}
		return ans;
	}
	void pushAllData(vector<int> &v,ListNode *list){
		while (list){
			v.push_back(list->val);
			list = list->next;
		}
		

	}
};
