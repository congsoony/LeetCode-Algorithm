class Solution(object):
    def isValidSerialization(self, preorder):
        l = preorder.split(',')
        slot =1
        for i in l:
            slot-=1
            if slot<0:return False
            if i.isdigit():
                slot+=2

        return slot==0
    
        
