//https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        if(n==0)
            return 0;
        int ans=0;
        int final_ans=0;
        for(int i=0;i<tokens.size();i++){
            
            if(P>=tokens[i]){
                cout<<tokens[i]<<" ";
                P-=tokens[i];
                ans+=1;
            }
            else if(P<tokens[i] && ans>0){
                cout<<tokens[tokens.size()-1]<<" ";
                P+=tokens[tokens.size()-1];
                ans-=1;
                i-=1;
                tokens.pop_back();
            }
            final_ans=max(ans,final_ans);
        }
        return final_ans;
    }
};