class Solution {
    public static int[] tree;
    public static int M = (int) 1e6 + 1;

    public int[][] reconstructQueue(int[][] people) {

        
        
        Arrays.sort(people, (a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1];
            return b[0] - a[0];
        });

        List<int[]> list = new ArrayList<>();
        for (int p[] : people) {
            list.add(p[1],p);
        }
        return list.toArray(new int[people.length][]);

    }


}