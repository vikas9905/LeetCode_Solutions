//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>in_degree(n,0);
        for(int i=0;i<edges.size();i++){
            in_degree[edges[i][1]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(in_degree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};