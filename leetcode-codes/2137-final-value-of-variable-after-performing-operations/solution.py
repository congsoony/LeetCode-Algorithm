class Solution(object):
    def finalValueAfterOperations(self, operations):
        d={'--X':-1,'X--':-1,'++X':1,'X++':1}
        res = 0 
        for o in operations:res+=d[o]
        return res
