//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>arr(256,0);
        int n=s.length();
        int ans=0;
        vector<int>index(128,0);
        for(int j=0,i=0;j<n;j++){
            i=max(index[s[j]],i);
            ans=max(ans,j-i+1);
            index[s[j]]=j+1;
        }
        return ans;
        
    }
};