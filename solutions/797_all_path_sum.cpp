//https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>>path;
    void dfsutil(vector<vector<int>>graph,vector<int>vis,int s,int d,int ind,vector<int>route){
        vis[s]=1;
        route.push_back(s);
        if(s==d){
            path.push_back(route);
        }
        for(auto i:graph[s]){
            if(!vis[i]){
                dfsutil(graph,vis,i,d,ind++,route);
            }
        }
        route.pop_back();
        vis[s]=0;
    }
    void dfs(vector<vector<int>>graph){
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>route;
        dfsutil(graph,vis,0,n-1,0,route);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph);
        return path;
    }
};