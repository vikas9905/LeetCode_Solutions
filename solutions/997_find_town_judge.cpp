//https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    void find_in_degree(vector<int>&ind,vector<int>*graph,int n){
       for(int i=0;i<n;i++){
           for(auto j:graph[i]){
               ind[j]++;
           }
       }
    }
    
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> *graph=new vector<int>[N];
        for(int i=0;i<trust.size();i++){
            graph[trust[i][0]-1].push_back(trust[i][1]-1);
        }
        vector<int>in_degree(N,0);
        find_in_degree(in_degree,graph,N);
        for(int i=0;i<N;i++){
            if(graph[i].size()==0 && in_degree[i]==N-1){
                return i+1;
            }
        }
        return -1;
    }
};