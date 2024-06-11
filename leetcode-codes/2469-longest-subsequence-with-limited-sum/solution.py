import bisect
class Solution(object):
    def answerQueries(self, nums, queries):
        nums.sort()
        n,m=len(nums),len(queries)
        prefix,res = [0]*n,[0]*m
        prefix[0]=nums[0]
        
        for i in range(1,n):prefix[i]=prefix[i-1]+nums[i]
        for i in range(m):   
            res[i]=bisect.bisect_right(prefix,queries[i])
        return res
