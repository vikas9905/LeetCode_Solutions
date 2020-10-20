//https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    obstacleGrid[i][j]=-1;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(obstacleGrid[0][i]==-1)
                break;
            obstacleGrid[0][i]=1;
        }
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0]==-1)
                break;
            obstacleGrid[i][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]!=-1){
                    if(obstacleGrid[i-1][j]!=-1)
                        obstacleGrid[i][j]+=obstacleGrid[i-1][j];
                    if(obstacleGrid[i][j-1]!=-1){
                        obstacleGrid[i][j]+=obstacleGrid[i][j-1];
                    }
                }
            }
        }
        return (obstacleGrid[n-1][m-1]>0)?obstacleGrid[n-1][m-1]:0;
    }
};