from collections import Counter
class Solution(object):
    def countKDifference(self, nums, k):
        c=Counter(nums)
        res=0
        for key,val in c.items():
            res+=c[key-k]*val
            res+=c[key+k]*val
        return res//2
