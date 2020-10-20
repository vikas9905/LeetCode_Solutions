//https://leetcode.com/problems/01-matrix/submissions/

class Solution {
public:
    bool safe(int p,int q,int r,int c){
        return (p>=0 && p<r && q>=0 && q<c);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dis(row,vector<int>(col,INT_MAX));
        queue<pair<int,int>>bfs;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    dis[i][j]=0;
                    bfs.push({i,j});
                }
            }
        }
        while(!bfs.empty()){
            int p=bfs.front().first;
            int q=bfs.front().second;
            bfs.pop();
            for(int i=0;i<4;i++){
                if(safe(p+dx[i],q+dy[i],row,col) && dis[p+dx[i]][q+dy[i]]>dis[p][q]+1){
                    dis[p+dx[i]][q+dy[i]]=dis[p][q]+1;
                    bfs.push({p+dx[i],q+dy[i]});
                }
            }
        }
        return dis;
    }
};