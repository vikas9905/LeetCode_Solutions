//https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
        }
        int n=ceil(nums.size()/(float)2);
        map<int,int>::iterator i;
        for(i=mp.begin();i!=mp.end();i++){
            cout<<i->first<<" "<<i->second<<"\n";
            if(i->second>=n){
                ans=i->first;
                break;
            }
        }
        return ans;
    }
};