//https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>mp1,mp2;
        char ans;
        int i=0;
        for(i=0;i<s.length();i++){
            mp1[s[i]]+=1;
            mp2[t[i]]+=1;
        }
        while(i<t.length()){
            mp2[t[i]]+=1;
            i+=1;
        }
        map<char,int>::iterator j;
        for(j=mp2.begin();j!=mp2.end();j++){
            if(j->second!=mp1[j->first]){
                ans= j->first;
                break;
            }
        }
        return ans;
    }
};