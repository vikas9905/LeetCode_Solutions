//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    
    string LCP(string s1,string s2){
        string result;
        for(int i=0,j=0;i<s1.length() && j<s2.length();i++,j++){
            if(s1[i]!=s2[j])
                break;
            result+=s1[i];
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            prefix=LCP(prefix,strs[i]);
        }
        return prefix;
    }
};