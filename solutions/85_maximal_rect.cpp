//https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    
    int max_hist(vector<int>arr){
        int n=arr.size();
        stack<int>s;
        int area_with_top=0;
        int area=0;
        int i=0;
        while(i<n){
            if(s.empty() || arr[s.top()]<=arr[i])
                s.push(i++);
            else{
                int tp=s.top();
                s.pop();
                area_with_top=arr[tp]*(s.empty()? i:i-s.top()-1);
                if(area_with_top>area)
                    area=area_with_top;
            }
        }
        while(!s.empty()){
            int tp=s.top();
            s.pop();
            area_with_top=arr[tp]*(s.empty()? i:i-s.top()-1);
            if(area_with_top>area)
                area=area_with_top;
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>>arr;
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    temp.push_back(0);
                else
                    temp.push_back(1);
                
            }
            arr.push_back(temp);
        }
        int res=max_hist(arr[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j])
                    arr[i][j]+=arr[i-1][j];
            }
            res=max(res,max_hist(arr[i]));
        }
     return res;
    }
};