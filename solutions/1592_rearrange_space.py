#https://leetcode.com/problems/rearrange-spaces-between-words/

class Solution:
    def reorderSpaces(self, text: str) -> str:
        l=text.split(" ")
        cnt=l.count("")
        words=len(l)-cnt
        cnt+=words-1
        dis=cnt//(words-1) if words-1>0 else 0
        rem=cnt%(words-1) if words-1>0 else cnt
        new_str=''
        while l.count("")>0:
            l.remove("")
        for i in range(len(l)-1):
            new_str+=l[i]+" "*dis
        new_str+=l[-1]
        while rem>0:
            new_str+=" "
            rem-=1
        return new_str
        
        