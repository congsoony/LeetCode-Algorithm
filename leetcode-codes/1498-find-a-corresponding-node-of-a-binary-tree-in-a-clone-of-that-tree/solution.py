from collections import deque
class Solution(object):
    def getTargetCopy(self, original, cloned, target):
        q = deque()
        q.append((original,cloned))
        while q:
            original,cloned = q.popleft()
            if not original :continue
            if original == target:
                return cloned
            q.append((original.left,cloned.left))
            q.append((original.right,cloned.right))            
        return None
