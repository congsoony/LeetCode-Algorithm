class Solution {

public void nextPermutation(int[] nums) {
        int i = nums.length-2;
        if(nums.length==1)return;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i<0){
            i=0;
            int j= nums.length-1;
             while(i<j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j]= temp;
            i++;
            j--;
        }
            return;
        }
        int j =nums.length-1;
        while(nums[j]<=nums[i])j--;
        int temp = nums[i];
        nums[i]= nums[j];
        nums[j] = temp;
        j = nums.length-1;
        i++;
        while(i<j){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j]= temp;
            i++;
            j--;
        }
    }
}