class Solution {
public:
	int maxArea(vector<int>& height) {
		deque<int> dq(height.begin(), height.end());
		int Max = 0;
		while (dq.size() > 1){
			int width = dq.size() - 1;
			int height;
			if (dq.front() > dq.back())
			{
				height = dq.back();
				dq.pop_back();
			}
			else {
				height = dq.front();
				dq.pop_front();
			}
			Max = max(Max, height*width);
		}
		return Max;
	}
};
