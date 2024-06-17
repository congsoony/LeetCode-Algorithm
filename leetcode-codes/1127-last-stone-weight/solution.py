import heapq
class Solution(object):
    def lastStoneWeight(self, stones):
        st = [-i for i in stones]
        heapq.heapify(st)
        
        while len(st)>1:
            y = -heapq.heappop(st)
            x = -heapq.heappop(st)
            if y!=x:
                heapq.heappush(st,-(y-x))
        return 0 if not st else -st[0]
