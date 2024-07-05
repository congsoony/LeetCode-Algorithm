class Solution(object):
    def climbStairs(self, n):
        self.dp = [-1]*(n+5)
        return self.up(0,n)
    def up(self,h,n):
        if n==1 or n==2:return n
        if h==n:return 1
        if h>n:return 0
        if self.dp[h]!=-1:return self.dp[h]
        self.dp[h]= self.up(h+1,n)+self.up(h+2,n)
        return self.dp[h]
