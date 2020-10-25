//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        int n=prices.size();
        if(n==0)
            return 0;
        int max_proffit=0;
        int curr=prices[0];
       for(int i=0;i<n;i++){
           curr=min(curr,prices[i]);
           max_proffit=max(prices[i]-curr,max_proffit);
       }   
        return max_proffit;
    }
};