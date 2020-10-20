//https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s=to_string(x);
        int n=s.length()-1;
        for(int i=0;i<s.length();i++,n--){
            if(s[i]!=s[n]){
                return false;
            }
        }
        return true;
    }
};