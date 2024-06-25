from collections import deque
class Solution(object):
    def eventualSafeNodes(self, graph):
        n = len(graph)
        l=[]*n
        indegree =[0]*n
        v=[[]for i in range(n)]

        for i in range(n):
            for node in graph[i]:
                indegree[i]+=1
                v[node].append(i)
        res = []
        q = deque()
        for i in range(n):
            if indegree[i]==0:
                q.append(i)
        while q:
            cur = q.popleft()
            res.append(cur)
            for next in v[cur]:
                indegree[next]-=1
                if indegree[next]==0:
                    q.append(next)
        res.sort()
        return res
