class Solution(object):
    def splitArray(self, nums, k):
        n = len(nums)
        dp=[[-1 for j in range(k+1)]for i in range(n+1)]
        prefix = [0]*(n+1)
        for i in range(1,n+1):prefix[i]=prefix[i-1]+nums[i-1]
        def dfs(i,j):
            if j==1:
                return prefix[i]
            if dp[i][j]!=-1:
                return dp[i][j]
            inf = int(1e10)
            for l in range(j-1,i):
                beforesum = prefix[i]-prefix[l]
                large = max(beforesum,dfs(l,j-1))
                inf = min(inf,large)
            dp[i][j]=inf
            return inf
        return dfs(n,k)
