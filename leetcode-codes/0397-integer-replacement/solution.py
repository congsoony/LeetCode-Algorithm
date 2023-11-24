class Solution(object):
    def integerReplacement(self, n):
        check =set()
        q = deque()
        
        check.add(n)
        q.append((n,0))
        while q:
            cur,cnt = q.popleft()
            if cur==1:
                return cnt
            if cur %2==0:
                if cur//2 not in check:
                    q.append((cur//2,cnt+1))
                    check.add(cur//2)
            else :
                if cur-1 not in check :
                    q.append((cur-1,cnt+1))
                    check.add(cur-1)
                if cur+1<=(2**31 +10) and cur+1 not in check :
                    q.append((cur+1,cnt+1))
                    check.add(cur+1)
        
