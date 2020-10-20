//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s=="")
            return s;
        int start=0,low=0,high=0,max_len=1;
        string ans;
        int n=s.length();
        for(int i=0;i<n;i++){
            low=i-1;
            high=i;
            while(low>=0 && high<n && s[low]==s[high]){
                if(max_len<high-low+1){
                    max_len=high-low+1;
                    start=low;
                }
                low-=1;
                high+=1;
            }
         low=i-1;
         high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                if(max_len<high-low+1){
                    max_len=high-low+1;
                    start=low;
                }
                low-=1;
                high+=1;
            }
        }
     for(int i=start;i<start+max_len;i++){
         ans+=s[i];
     }
        return ans;
    }
};