//https://leetcode.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max_diff=0;
        for(int i=1;i<nums.size();i++){
            int diff=nums[i]-nums[i-1];
            if(diff>max_diff)
                max_diff=diff;
        }
        return max_diff;
    }
};