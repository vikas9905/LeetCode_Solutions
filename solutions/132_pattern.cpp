//https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1] && nums[i-1]<nums[i+1]){
                return true;
            }
        }
        return false;
    }
};