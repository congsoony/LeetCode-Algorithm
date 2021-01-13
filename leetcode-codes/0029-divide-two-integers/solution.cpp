class Solution {
public:
	int divide(int dividend, int divisor) {
		long long a = dividend;
		long long b = divisor;
		return a/b>INT_MAX?INT_MAX:a/b;
	}
};
