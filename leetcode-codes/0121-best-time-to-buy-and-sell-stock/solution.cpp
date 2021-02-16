class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxsell = 0;
		int minstock = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			minstock=min(prices[i] , minstock);
			maxsell = max(maxsell, prices[i] - minstock);
		}
		return maxsell;
	}
};
