class Solution {
		public int[] answerQueries(int[] nums, int[] queries) {
	        Arrays.sort(nums);
	        int sum[] =new int[nums.length+1];
	        for(int i =1;i<sum.length;i++) sum[i]=sum[i-1]+nums[i-1];
	        int ans[] =new int[queries.length];
	        for(int i=0;i<queries.length;i++)
	        	ans[i]=lower_bound(sum, queries[i]);
	        return ans;
	    }
		
		public int lower_bound(int sum[],int k) {
			int l=0;
			int r =sum.length-1;
			while (l<=r) {
				int mid = (l+r)/2;
				if (sum[mid]>k) r=mid-1;
				else l=mid+1;
			}
			return l-1;
		}
	}
