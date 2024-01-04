from bisect import bisect_left
class Solution(object):
    def twoSum(self, numbers, target):
        for i in range(len(numbers)):
            idx = bisect_left(numbers,target-numbers[i])
            if idx<len(numbers) and numbers[i]<numbers[idx] and numbers[i]+numbers[idx] ==target:
                return [i+1,idx+1]
            if idx==i and i+1 <len(numbers) and numbers[i]==numbers[i+1]:
                return [i+1,i+2]
        return None
