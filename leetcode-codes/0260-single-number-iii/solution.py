from collections import Counter
class Solution(object):
    def singleNumber(self, nums):
        m = Counter(nums)
        res = []
        for k,val in m.items():
            if val==1:res.append(k)
        return res
        
