import sys
from collections import Counter
class Solution(object):
    def isPalindrome(self, s):
       phrase = s.lower()
    
       word = ''.join([i for i in phrase if i.isalpha() or i.isdigit()])
       l,r = 0,len(word)-1
       while l<=r:
           if word[l]!=word[r]:
               return False
           l+=1
           r-=1
       return True

