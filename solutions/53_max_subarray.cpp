//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int max_far=0,max_curr=0;
      for(int i=0;i<nums.size();i++){
          max_curr+=nums[i];
          if(max_far<max_curr)
              max_far=max_curr;
          else if(max_curr<0){
              max_curr=0;
          }
      }
     return (max_far>0)? max_far:*max_element(nums.begin(),nums.end());
    }
};