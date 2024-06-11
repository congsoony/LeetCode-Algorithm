import sys
import math
from collections import Counter
class Solution(object):
    def evalRPN(self, tokens):
        l=[]
        for s in tokens:
            if s in "+-*/":
                x = l[-2]
                y = l[-1]
                l.pop()
                l.pop()    
                if s=="+":
                    l.append(x+y)
                elif s=="-":
                    l.append(x-y)
                elif s=="*":
                    l.append(x*y)
                else:
                    l.append(int(x/y))
            else:
                l.append(int(s))
        return l[-1]
