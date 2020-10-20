#https://leetcode.com/problems/reverse-integer/

class Solution:
    def reverse(self, x: int) -> int:
        flag=0
        if(x<0):
            flag=1
            x=(-1)*x
        ans=str(x)
        num=int(ans[::-1])
        if num>=(-2)**31-1 and num<=(2)**31-1:
            return num if flag!=1 else num*-1
        return 0
        