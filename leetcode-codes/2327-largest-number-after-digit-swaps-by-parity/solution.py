class Solution(object):
    def largestInteger(self, num):
        s = str(num)
        l = [int(i)%2==1 for i in s]
        odd,even=[],[]
        for i in s:
            if int(i)%2:
                odd.append(i)
            else:
                even.append(i)
        odd.sort()
        even.sort()
        res=''
        for i in range(len(l)):
            if l[i]:
                res+=odd.pop()
            else:
                res+=even.pop()
        return int(res)
