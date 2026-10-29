class Solution {
    public static int n;
    public static List<Integer>[] list;
    public static int[] check;
    public boolean possibleBipartition(int n, int[][] dislikes) {
        this.n = n;
        list= new List[n+1];
        check = new int[n+1];
        for(int i =0;i<=n;i++)
            list[i]=new ArrayList<>();
        for(int d[]:dislikes){
            list[d[0]].add(d[1]);
            list[d[1]].add(d[0]);
        }
        Arrays.fill(check, -1);
        boolean flag=true;
        for(int i =1;i<=n;i++){
            if(check[i]==-1){
                if(dfs(i,0)==false){
                    flag= false;
                    break;
                }
            }
        }
        return flag;
    }
    public static boolean dfs(int cur,int num){
        boolean flag = true;
        check[cur]=num;
        for(int next:list[cur]){
            if(check[next]==-1){
                flag &=dfs(next,(num+1)%2);
            }
            else if(check[next]==num){
                return false;
            }
        }
        return flag;
    }
}