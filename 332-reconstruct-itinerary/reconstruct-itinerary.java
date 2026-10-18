class Solution {
    Map<String,TreeMap<String,Integer>> map = new HashMap<>();
    List<String> res = new ArrayList<>();   
    public List<String> findItinerary(List<List<String>> tickets) {
        for(List<String> t : tickets){
            map.computeIfAbsent(t.get(0), k->new TreeMap<>()).merge(t.get(1), 1, Integer::sum);
        }
        dfs("JFK");
        Collections.reverse(res);
        return res;
    }
    public void dfs(String cur){
        while(map.containsKey(cur)&& !map.get(cur).isEmpty()){
            TreeMap<String,Integer> dests = map.get(cur);
            String next = dests.firstKey();
            dests.compute(next,(k,count)->count==1?null:count-1);
            dfs(next);
        }
        res.add(cur);
    }
}