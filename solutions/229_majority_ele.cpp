//https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
        }
        vector<int>ans;
        int cmp=nums.size()/3;
        map<int,int>::iterator i;
        for(i=mp.begin();i!=mp.end();i++){
            if(i->second>cmp)
                ans.push_back(i->first);
        }
        return ans;
    }
};