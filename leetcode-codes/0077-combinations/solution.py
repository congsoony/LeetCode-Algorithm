from itertools import combinations
class Solution(object):
    def combine(self, n, k):
        l = [i for i in range(1,n+1)]
        c= list(combinations(l,k))
        c2 = [list(i) for i in c]
        return c2
