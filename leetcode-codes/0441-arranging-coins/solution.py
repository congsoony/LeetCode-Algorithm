class Solution(object):
    def arrangeCoins(self, n):
        l,r = 0,1000000
        res = 10000000
        while l<=r:
            mid = (l+r)//2
            if n < self.summ(mid) :
                res=min(res,mid)
                r=mid-1
            else:
                l=mid+1
        return res-1
    def summ(self,n):
        return ((n)*(n+1))//2
