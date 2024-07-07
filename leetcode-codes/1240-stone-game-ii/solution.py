class Solution(object):
    def stoneGameII(self, piles):
        n = len(piles)
        dp =[[[-1 for i in range(n+1)] for j in range(n)] for k in range(2)]
        def minimax(i, M, isAlice):
            if i >= n:
                return 0
            if dp[isAlice][i][M]!=-1: return dp[isAlice][i][M]
            if isAlice:
                max_score = float('-inf')
                current_sum = 0
                for x in range(1, 2 * M + 1):
                    if i + x <= n:
                        current_sum += piles[i + x - 1]
                        max_score = max(max_score, current_sum + minimax(i + x, max(M, x), False))
                dp[isAlice][i][M]=max_score   
                return max_score
            else:
                min_score = float('inf')
                for x in range(1, 2 * M + 1):
                    if i + x <= n:
                        min_score = min(min_score, minimax(i + x, max(M, x), True))
                dp[isAlice][i][M]=min_score 
                return min_score
        return minimax(0, 1, True)
