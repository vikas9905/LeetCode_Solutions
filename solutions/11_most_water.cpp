//https://leetcode.com/problems/container-with-most-water/

#include<algorithm>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int i=0;
        int j=height.size()-1;
        while (i<height.size() && j>=0){
            int area=min(height[i],height[j])*(j-i);
            if(max_area<area)
                max_area=area;
            if(height[i]<height[j])
                i+=1;
            else
                j-=1;
        }
        return max_area;
    }
};