class Solution {
    public  int minMutation(String startGene, String endGene, String[] bank) {
        HashSet<String> set = new HashSet<>();
        HashSet<String> check = new HashSet<>();
        for(String s:bank)set.add(s);
        if(!set.contains(endGene))return -1;
        Queue<String> q= new LinkedList<>();
        int cnt = 0;
        q.add(startGene);
        String s= "ACGT";
        while(!q.isEmpty()){
            int qsize=q.size();
            while(qsize>0){
                qsize--;
                String cur = q.poll();
                char []chart = cur.toCharArray();
                if(cur.equals(endGene))return cnt;

                for(int i=0;i<chart.length;i++){
                    for(int j=0;j<s.length();j++){
                        char c= chart[i];
                        chart[i]=s.charAt(j);
                        if(!check.contains(new String(chart))&&set.contains(new String(chart))){
                            q.add(new String(chart));
                            check.add(new String(chart));
                        }
                        chart[i]= c;
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
}
