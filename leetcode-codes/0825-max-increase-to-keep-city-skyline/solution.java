class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int n = grid.length;
        int res=0;
        int colmax[] =new int[n];
        int rowmax[] =new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rowmax[i]=Math.max(rowmax[i],grid[i][j]);
                colmax[i]=Math.max(colmax[i],grid[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res+=Math.abs(grid[i][j]-Math.min(colmax[j],rowmax[i]));
            }
        }
        return res;
    }
}

