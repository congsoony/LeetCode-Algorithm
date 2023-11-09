class Solution(object):
    def findRepeatedDnaSequences(self, s):
        m = {}
        res = []
        if len(s)<10 :
            return res
        for i in range(0,len(s)-9):
            temp = s[i:i+10]
            if not m.get(temp) :
                m[temp]=1
            else :
                m[temp]+=1
            if m[temp]==2:
                res.append(temp)
        return res
        
