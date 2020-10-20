#https://leetcode.com/problems/rotate-array/

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i=len(nums)
        nums+=nums[len(nums)-k:]+nums[:len(nums)-k]
        while(i):
            i-=1
            nums.pop(0)