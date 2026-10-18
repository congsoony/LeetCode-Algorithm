class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        boolean [][]check =new boolean[n][1<<n];
        Queue<int[]> q = new LinkedList<>();
        for(int i =0;i<n;i++){
            q.add(new int[]{i,1<<i,0});
            check[i][1<<i]=true;
        }
        while(!q.isEmpty()){
            int nodes[] = q.poll();
            int cur = nodes[0];
            int bit = nodes[1];
            int dist = nodes[2];

            if(bit==(1<<n)-1)
                return dist;
            for(int next : graph[cur]){
                int nextbit = bit|(1<<next);
                if(!check[next][nextbit]){
                    check[next][nextbit]=true;
                    q.add(new int[]{next,nextbit,dist+1});
                }
            }
        }
        return 0;
    }
}