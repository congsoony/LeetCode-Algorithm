class Solution {
   
    public static int bsearch(int []nums,int target){
        int l=0;
        int r = nums.length-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]<target)l=mid+1;
            else if(nums[mid]>target) r=mid-1;
            else return mid;
        }
        return -1;
    }
    public int[] searchRange(int[] nums, int target) {
        if(bsearch(nums,target)==-1){
            return new int[]{-1,-1};
        }
        int res1 = lowerbound(nums,target);
        int res2 = upperbound(nums,target);
        if(nums[res2]!=target)res2--;
        return new int[]{res1,res2};
    }
    public static int lowerbound(int[] nums,int target){
        int l=0;
        int r = nums.length-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]<target)l=mid+1;
            else r=mid;
        }
        return r;
    }
    public static int upperbound(int[] nums,int target){
        int l=0;
        int r = nums.length-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]<=target)l=mid+1;
            else r=mid;
        }
        return r;
    }

}
