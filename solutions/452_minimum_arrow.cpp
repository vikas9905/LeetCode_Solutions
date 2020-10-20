//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

bool myfun(vector<int>point1,vector<int>point2){
    if(point1[1]<point2[1])
        return true;
    else if(point1[1]>point2[1])
        return false;
    else{
        return (point1[0]<point2[0]);
    }
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        sort(points.begin(),points.end(),myfun);
        long long c=1;
        long long end=points[0][1];
        for(int i=0;i<points.size();i++){
            if(points[i][0]<=end)
                continue;
            c++;
            end=points[i][1];
        }
        return c;
    }
};