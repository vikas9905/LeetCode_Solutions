#https://leetcode.com/problems/largest-number/

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        l=[]
        for i in nums:
            s=list(str(i))
            l+=s
        l.sort(reverse=True)
        ans=""
        for i in l:
            ans+=i
        return ans