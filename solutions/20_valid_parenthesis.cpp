//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    
    bool check(char s,char t){
        if(s=='(' && t==')')
            return true;
        else if(s=='{' && t=='}')
            return true;
        else if(s=='[' && t==']')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
              if(st.empty()||s[i]=='{' || s[i]=='(' || s[i]=='['){
                  st.push(s[i]);
                  continue;
              }
              if(check(st.top(),s[i])){
                  st.pop();
              }
            else{
                return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};