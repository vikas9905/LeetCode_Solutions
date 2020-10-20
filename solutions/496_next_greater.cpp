//https://leetcode.com/problems/next-greater-element-i/submissions/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int>next;
        vector<int>ans;
        stack<int>s;
        if(nums2.size()==0){
            return ans;
        }
        s.push(nums2[0]);
        for(int i=1;i<nums2.size();i++){
            if(s.empty()){
                s.push(nums2[i]);
                continue;
            }
            while(!s.empty() && s.top()<nums2[i]){
                next[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
            next[s.top()]=-1;
            s.pop();
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(next[nums1[i]]);
        }
        return ans;
    }
};