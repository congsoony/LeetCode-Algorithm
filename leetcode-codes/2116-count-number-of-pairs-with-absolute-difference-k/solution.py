from collections import Counter
class Solution(object):
    def countKDifference(self, nums, k):
        c = Counter(nums)
        res = 0
        for x, val in c.items():
            res+=c[x+k]*val
            res+=c[x-k]*val
        return res//2
