//https://leetcode.com/problems/champagne-tower/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101,vector<double>(101,0));
        dp[0][0]=(double)poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                double sub=(dp[i][j]-1)/2;
                if(sub>0){
                    dp[i+1][j]+=sub;
                    dp[i+1][j+1]+=sub;
                }
            }
        }
        if(dp[query_row][query_glass]>=1)
            return (double)1;
        else{
            return dp[query_row][query_glass];
        }
    }
};