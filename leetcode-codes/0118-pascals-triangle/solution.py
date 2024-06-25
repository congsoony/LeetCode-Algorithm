class Solution(object):
    def generate(self, numRows):
        res = []
        for i in range(numRows):
            l=[]
            for j in range(i+1):
                if j==0 or j==i:
                    l.append(1)
                else:
                    l.append(res[-1][j]+res[-1][j-1])
            res.append(l)
        return res
