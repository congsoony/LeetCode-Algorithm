class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<double> v;
		int l = 0, r = 0;
		while (l < nums1.size() && r < nums2.size()){
			if (nums1[l] < nums2[r])
				v.push_back(nums1[l++]);
			else
				v.push_back(nums2[r++]);
		}
		if (l<nums1.size()){
			add(v, nums1, l);
		}
		else{
			add(v, nums2, r);
		}
		if (v.size() % 2)
			return v[v.size() / 2];
		return (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;

	}
	void add(vector<double> &v, vector<int> &add,int idx){
		for (int i = idx; i < add.size(); i++)
			v.push_back(add[i]);
	}
};
