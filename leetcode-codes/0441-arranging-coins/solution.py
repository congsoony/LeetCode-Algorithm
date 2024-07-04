class Solution(object):
    def arrangeCoins(self, n):
        l = 1
        r = 100000
        res= 1
        while l<=r:
            mid = (l+r)//2
            if n<self.summ(mid):
                r=mid-1
            else:
                res=max(res,mid)
                l=mid+1
        return res

    def summ(self,n):
        return (n*(n+1))//2
