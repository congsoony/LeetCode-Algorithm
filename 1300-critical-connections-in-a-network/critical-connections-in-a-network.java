class Solution {
    public static int id,n;
    public static int [] group,p;
    public static int counter = 0 ;
    public static List<Integer> st = new ArrayList<>();
    public static List<Integer>[] list;
    public static  List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        list = new List[n];
        for(int i =0;i<n;i++)list[i]=new ArrayList<>();
        group = new int[n];
        p=new int[n];
        for(List<Integer> c : connections){
            list[c.get(0)].add(c.get(1));
            list[c.get(1)].add(c.get(0));
        }
        for(int i =0;i<n;i++){
            if(p[i]==0)dfs(i,-1);
        }
        List<List<Integer>> res = new ArrayList<>();
        for(List<Integer> c : connections){
            if(p[c.get(0)]!= p[c.get(1)]){
                res.add(new ArrayList<>(Arrays.asList(c.get(0),c.get(1))));
            }
        }
        return res;
    }
    
    

    public static int dfs(int cur,int before){
        int parent = group[cur]= ++id;
        st.add(cur);
        for(int next : list[cur]){
            if(next==before)continue;
            if(group[next]==0){
                parent = Math.min(parent, dfs(next,cur));
            }
            else if(p[next] ==0){
                parent = Math.min(parent, group[next]);
            }
        }
        if(group[cur]==parent){
            counter++;
            while(true){
                int t = st.removeLast();
                p[t]=counter;
                if(t==cur)break;
            }
        }
        return parent;
    }
}