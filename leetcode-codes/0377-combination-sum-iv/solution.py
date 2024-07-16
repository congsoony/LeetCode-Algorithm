import sys
sys.setrecursionlimit(1000000)
class Solution(object):
    def combinationSum4(self, nums, target):
        n = len(nums)
        dp = [-1]*(target+1)

        def dfs(total=0):
            if total==target:
                return 1
            if total >target:
                return 0
            if dp[total]!=-1:
                return dp[total]
            res = 0
            for x in nums:
                res +=dfs(total+x)
            dp[total]=res
            return res
        return dfs()

