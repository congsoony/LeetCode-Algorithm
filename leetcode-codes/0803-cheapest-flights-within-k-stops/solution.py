from collections import deque
class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        
        q =deque()
        q.append((src,0,0))
        inf = 10000000000000
        dist=[inf]*n
        graph = [[] for i in range(n)]
        for f in flights:
            graph[f[0]].append((f[1],f[2]))
        dist[src]=0
        k+=1
        while q:
            cur,cost,cnt = q.popleft()
            ncnt =cnt+1
            for next,c in graph[cur]:
                ncost = cost+c
                if ncnt<=k and dist[next]>ncost:
                    dist[next]=ncost
                    q.append((next,ncost,ncnt))
        return dist[dst] if dist[dst]!=inf else -1
