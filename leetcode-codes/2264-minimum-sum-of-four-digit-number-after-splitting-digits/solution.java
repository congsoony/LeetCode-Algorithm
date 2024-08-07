class Solution {
    public int minimumSum(int num) {
        String number = Integer.toString(num);
        int res = 100000000;
        for(int i=1;i<15;i++){
            String []nums =new String[2];
            nums[0]="";
            nums[1]="";
            for(int j=0;j<4;j++){
                if(((1<<j) &i) ==0){
                    nums[0]+=number.charAt(j);
                }
                else {
                    nums[1] += number.charAt(j);
                }
                
            }
            char a[]=nums[0].toCharArray();
            char b[]= nums[1].toCharArray();
            Arrays.sort(a);
            Arrays.sort(b);
            nums[0] = new String(a);
            nums[1] = new String(b);
            int t = Integer.parseInt(nums[0])+Integer.parseInt(nums[1]);
            res = Math.min(res,t);
        }
        return res;
    }
}
