#https://leetcode.com/problems/two-sum/


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic={}
        for i in range(len(nums)):
            dic[nums[i]]=i
        for i in range(len(nums)):
            s=target-nums[i]
            ind=dic.get(s,-1)
            if ind!=-1  and i!=ind:
                return([i,ind])
                break
            
        