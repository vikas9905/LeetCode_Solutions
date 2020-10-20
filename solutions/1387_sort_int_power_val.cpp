//https://leetcode.com/problems/sort-integers-by-the-power-value/

bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second)
        return true;
    else if(p1.second>p2.second)
        return false;
    else{
        return p1.first<p2.first;
    }
}

class Solution {
public:
    unordered_map<int,int> dp;
    
    int solve(int x){
        if(dp.count(x)!=0)
            return dp[x];
        if(x%2==0){
            return dp[x]=solve(x/2)+1;
        }
        else{
           return dp[x]=solve(3*x+1)+1;
        }
    }
    
    int getKth(int lo, int hi, int k) {
        //dp(1001,0);
        dp[1]=0;
        for(int i=lo;i<=hi;i++){
            solve(i); 
        }
        vector<pair<int,int>>ans;
        for(int i=lo;i<=hi;i++){
            ans.push_back(make_pair(i,dp[i]));
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans[k-1].first;
    }
};