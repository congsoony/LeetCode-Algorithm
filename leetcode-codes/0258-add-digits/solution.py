class Solution(object):
    def addDigits(self, num):
        while num//10 !=0:
            temp = 0
            while num:
                temp+=num%10
                num//=10
            num=temp
        return num

        
