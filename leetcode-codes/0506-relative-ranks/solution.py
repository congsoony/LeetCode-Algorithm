from collections import Counter
class Solution(object):
    def findRelativeRanks(self, score):
        
        l = [(score[i],i) for i in range(len(score))]
        c = Counter({0:'Gold Medal',1:'Silver Medal',2:'Bronze Medal'})
        res = [0]*len(score)
        l.sort(key= lambda x:(-x[0]))
        for i in range(len(l)):
            res[l[i][1]] = c[i] if c[i] else str(i+1)
        return res
