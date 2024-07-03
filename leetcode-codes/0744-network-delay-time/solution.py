import heapq

class Solution(object):
    def networkDelayTime(self, times, n, k):
        graph =[[] for i in range(n+1)]
        for t in times:
            graph[t[0]].append((t[1],t[2]))
        inf =10000000000
        dist = [inf]*(n+1)
        pq = [(0,k)]
        dist[k]=dist[0]=0
        while pq:
            cost,cur = heapq.heappop(pq)
            if dist[cur]<cost:continue

            for next,c in graph[cur]:
                ncost = cost+c
                if ncost<dist[next]:
                    dist[next]=ncost
                    heapq.heappush(pq,(ncost,next))
        res = max(dist)
        return res if res !=inf else -1
