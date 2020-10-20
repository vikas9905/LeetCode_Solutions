//https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        set<pair<int,int> >s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(binary_search(nums.begin()+i+1,nums.end(),nums[i]+k)){
                s.insert(make_pair(nums[i],nums[i]+k));
            }
        }
        return s.size();
    }
};