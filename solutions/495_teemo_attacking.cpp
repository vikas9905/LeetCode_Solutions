//https://leetcode.com/problems/teemo-attacking/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        if(timeSeries.size()==0)
            return 0;
        for(int i=0;i<timeSeries.size()-1;i++){
            ans+=min((timeSeries[i+1]-timeSeries[i]),duration);
        }
        return ans+duration;
    }
};