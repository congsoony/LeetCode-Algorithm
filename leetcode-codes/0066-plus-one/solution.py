class Solution(object):
    def plusOne(self, digits):
        digits.reverse()
        res=0
        for i in range(0,len(digits)):
            res+= digits[i]*(10**i)
        res+=1
        ret=[]
        while res:
            ret.append(res%10)
            res//=10
        ret.reverse()
        return ret

