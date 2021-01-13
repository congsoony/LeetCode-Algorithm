class Solution {
public:
	int search(vector<int>& nums, int target) {
		return bsearch(nums,target);
	}
	int bsearch(vector<int> &v, int target){
		int left = 0;
		int right = v.size() - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (v[mid] == target)
				return mid;
			if (v[left] <= v[mid]){
				if (target < v[mid] && v[left] <= target)
					right = mid - 1;
				else
					left = mid + 1;
			}
			else {
				if (target > v[mid] && target<=v[right])
					left = mid + 1;
				else
					right = mid -1;
			}
		}

		return -1;
	}
};
