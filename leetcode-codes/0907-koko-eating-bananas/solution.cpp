class Solution {
public:
int minEatingSpeed(vector<int>& piles, int h) {
	int res =1e8;
	long long l=1,r=1e15;
	while(l<=r){
		long long mid = l+(r-l)/2;
		long long sum=0;
		for(int i : piles){
			sum+=i/mid;
			if(i%mid)sum++;
		}
		if(sum<=h){
			r=mid-1;
			res=mid;
		}
		else{
			l=mid+1;
		}
	}
	return res;
}
};
