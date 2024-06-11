from collections import Counter
class Solution(object):
    def isAnagram(self, s, t):
        c = Counter(s)
        c2 = Counter(t)
        for key in c2:
            if c[key]!=c2[key]:return False
        return len(s)==len(t)
    
