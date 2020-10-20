//https://leetcode.com/problems/gas-station/

class Solution {
public:
    
    bool check(vector<int> gas,vector<int>cost,int start,int sz){
        int end=-1;
        int next=gas[start];
        for(int i=start;i<sz+start-1;i++){
            if(next>=cost[i]){
                next=next-cost[i]+gas[i+1];
            }
            else
                return false;
        }
        if(next>=cost[sz+start-1]){
            return true;
        }
        return false;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int>arr1=gas;
        vector<int>arr2=cost;
        for(int i=0;i<gas.size();i++){
            arr1.push_back(gas[i]);
            arr2.push_back(cost[i]);
        }
        int i=0;
        while(i<n){
            if(arr1[i]>=arr2[i]){
                if(check(arr1,arr2,i,n)){
                    return i;
                }
            }
            i+=1;
        }
        return -1;
    }
};