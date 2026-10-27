class Solution {
public static int n;
    public static int [][][]dp;
    
    public static int maxProfit(int[] prices) {
        n = prices.length;
        dp =new int[n][3][2];
        for(int i =0;i<n;i++){
            for(int j =0;j<3;j++)
                Arrays.fill(dp[i][j], -1);
        }
        return dfs(0,2,0,prices);
    }
    public static int dfs(int cur,int k,int h,int prices[]){
        if(cur>=n || k==0)return 0;
        if(dp[cur][k][h]!=-1)return dp[cur][k][h];
        int nothing =dfs(cur+1,k,h,prices);
        int does = 0;
        if(h == 0){
            does = -prices[cur] + dfs(cur+1,k,1,prices);
        }
        else{
            does = prices[cur] + dfs(cur+1,k-1,0,prices);
        }
        return dp[cur][k][h] = Math.max(nothing, does);
    }
}