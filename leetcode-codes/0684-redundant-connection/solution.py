from collections import Counter
class Solution(object):
    def findRedundantConnection(self, edges):
        parent = [i for i in range(len(edges)+1)]

        def find(idx):
            if parent[idx]==idx:
                return idx
            parent[idx]=find(parent[idx])
            return parent[idx]
        def union(a,b):
            a =find(a)
            b= find(b)
            parent[b]=a
        res = []
        for e in edges:
            if find(e[0])!= find(e[1]):
                union(e[0],e[1])
            else:
                res = e
        return res
