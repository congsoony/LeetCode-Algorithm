from collections import Counter
class Solution(object):
    def findTheDifference(self, s, t):
        r = Counter(t)-Counter(s)
        res= ''
        for k,val in r.items():
            res= k
        return res
