import java.util.Arrays;
class Solution {
    public int maximizeSum(int[] nums, int k) {
	    int a =Arrays.stream(nums).max().getAsInt();
	    int sum = 0;
	    for(int i =a;i<k+a;i++)sum+=i;
	    return sum;
    }
}
