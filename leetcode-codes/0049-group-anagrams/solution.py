from collections import Counter
class Solution(object):
    def groupAnagrams(self, strs):
        res =[]
        m = Counter()
        for s in strs:
            s2 = ''.join(sorted(s))
            if not m[s2]:m[s2]=[]
            m[s2].append(s)
        for k,val in m.items():res.append(val)
        return res
