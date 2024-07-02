from collections import Counter
class Solution(object):
    def findingUsersActiveMinutes(self, logs, k):
        uamcnt =Counter()
        uam = [0]*k
        for l in logs:
            if uamcnt[l[0]]==0:
                uamcnt[l[0]]=set()
            uamcnt[l[0]].add(l[1])
        for k,val in uamcnt.items():
            uam[len(val)-1]+=1
        return uam

