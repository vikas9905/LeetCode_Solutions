//https://leetcode.com/problems/partition-labels/

class Solution {
public:
    
    vector<int> partitionLabels(string S) {
        vector<int>ans;
        vector<int>last_seen(128,-1);
        int len=S.length();
        while(len){
            int ind=S[len];
            if(last_seen[ind]==-1)
                last_seen[ind]=len;
            len-=1;
        }
        int i=0;
        int last_ele=last_seen[int(S[0])];
        int max_val=0;
        int last_val=0;
        while(i<S.length()){
            max_val=max(max_val,last_seen[int(S[i])]);
            if(i==max_val){
                ans.push_back(max_val-last_val+1);
                last_val+=*(ans.end()-1);
                max_val=0;
                last_ele=last_seen[int(S[i+1])];
            }
            i+=1;
        }
        return ans;
    }
};