class Solution(object):
    def hIndex(self, citations):
        l,r = 0,len(citations)-1
        res = 0
        while l<=r:
            mid = (l+r)//2
            idx = len(citations)-mid
            if citations[mid]>=idx:
                res = max(res,idx)
                r=mid-1
            else:
                l=mid+1
        return res
