//https://leetcode.com/problems/daily-temperatures/
//can you improve this
class Solution {
public:
    
    vector<int> find_next_greater(vector<int>&arr,int n){
        multimap<int,int>next;
        vector<int>ans;
        stack<int>s;
        if(n==0)
            return ans;
        s.push(0);
        for(int i=1;i<n;i++){
            if(s.empty()){
                s.push(i);
                continue;
            }
            while(!s.empty() && arr[i]>arr[s.top()]){
                next.insert({s.top(),i});
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            next.insert({s.top(),0});
            s.pop();
        }
        multimap<int,int>::iterator i;
        for(i=next.begin();i!=next.end();i++){
            if(i->second!=0){
                ans.push_back(abs(i->first-i->second));
            }
            else{
                ans.push_back(0);
            }
    }
        return ans;
    }
    
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        return find_next_greater(T,n);
    }
};