from collections import deque
class Solution(object):
    def canMeasureWater(self, x, y, target):
        check = set()
        q = deque()
        q.append((0,0))
        check.add((0,0))
        while q:
            a,b = q.popleft()
            if a+b == target:
                return True
            l = [(x,b),(a,y),(0,b),(a,0),(a-min(a,y-b),b+min(a,y-b)),(a+min(b,x-a),b-min(b,x-a))]
            for next in l:
                if next not in check:
                    check.add(next)
                    q.append(next)
        return False
