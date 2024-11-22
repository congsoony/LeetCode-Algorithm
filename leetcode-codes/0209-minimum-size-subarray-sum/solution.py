from collections import Counter
class Solution(object):
    def minSubArrayLen(self, target, nums):
        res = int(1e8)
        sum =[0]*(len(nums)+1)
        for i in range(len(nums)):
            sum[i+1]=sum[i]+nums[i]

        for i in range(1,len(sum)):
            if sum[i]<target:continue
            l = 0
            if i -l > res:
                l= i-res

            while sum[i]-sum[l]>=target:
                res = min(res,i-l)
                l+=1
        if res ==int(1e8) :return 0
        return res
