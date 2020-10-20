//https://leetcode.com/problems/course-schedule/

class Solution {
public:
    
    bool DFS(int *vis,int *rec,list<int>arr[],int u){
        if(rec[u])
            return false;
        if(vis[u])
            return true;
        vis[u]=1;
        rec[u]=1;
        vector<int>::iterator i;
        for(auto i:arr[u]){
            if(!DFS(vis,rec,arr,i))
                return false;
        }
        rec[u]=0;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int visited[numCourses];
        int rec[numCourses];
        memset(visited,0,sizeof visited);
        memset(rec,0,sizeof rec);
        list<int>li[numCourses];
        for(auto i:prerequisites){
            li[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!DFS(visited,rec,li,i)){
                return false;
            }
        }
        return true;
    }
};