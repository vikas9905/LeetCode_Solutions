#https://leetcode.com/problems/factorial-trailing-zeroes/

import math
class Solution:
    def trailingZeroes(self, n: int) -> int:
        s=list(str(math.factorial(n)))
        cnt=0
        i=len(s)-1
        while s[i]=='0':
            cnt+=1
            i-=1
        return cnt
        