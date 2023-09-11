class Solution {
public:
long long acc(long long t){
	return (t*(t+1))/2;
}
int minimumPossibleSum(int n, int target) {
	if(n==1) return 1;
	long long sum = 0;
	long long mod = 1e9+7;
	int t= target/2;
	if(n<t)return acc(n) % mod;
	sum+=acc(t)+acc(target+n-t-1) -acc(target-1);
	return sum%mod;
}

};
