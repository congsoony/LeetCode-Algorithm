class Solution(object):
    def maxProfit(self, prices):
        _min = prices[0]
        res = 0
        for i in range(1,len(prices)):
            res = max(prices[i]-_min,res)
            _min =min(_min,prices[i])
        return res
        
