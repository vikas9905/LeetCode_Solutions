#https://leetcode.com/problems/reverse-words-in-a-string/

class Solution:
    def reverseWords(self, s: str) -> str:
        new_str=""
        l=s.strip().split(" ")
        while l.count("")>0:
            l.remove("")
        for i in l:
            if i==l[-1]:
                new_str+=i[::-1]
                continue
            new_str+=i[::-1]+" "
        return new_str[::-1]