import heapq
import math
class Solution(object):
    def pickGifts(self, gifts, k):
        g = [-i for i in gifts]
        heapq.heapify(g)
        res = 0 
        while k>0:
            k-=1
            t = heapq.heappop(g)
            heapq.heappush(g,-int(sqrt(-t)))
        return -sum(g)
        
