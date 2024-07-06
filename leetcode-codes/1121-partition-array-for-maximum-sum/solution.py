class Solution(object):
    def maxSumAfterPartitioning(self, arr, k):
        self.dp=[-1]*(len(arr)+1)
        return self.dfs(0,arr,k)
    
    def dfs(self,i,arr,k):
        if i==len(arr):
            return 0
        if self.dp[i]!=-1:
            return self.dp[i]
        
        _max ,maxsum = 0,0

        for j in range(1,k+1):
            if i+j<=len(arr):
                _max = max(_max,arr[i+j-1])
                maxsum = max(maxsum,_max*j+self.dfs(i+j,arr,k))

        self.dp[i]=maxsum
        return self.dp[i]
        

# Example usage:
arr = [1, 15, 7, 9, 2, 5, 10]
k = 3
s= Solution()
print(s.maxSumAfterPartitioning(arr, k))  # Output: 84
