//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    
    bool bin_search(vector<int>arr,int target,int l,int r){
        if(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==target)
                return true;
            else if(arr[mid]>target){
                return bin_search(arr,target,l,mid-1);
            }
            else{
                return bin_search(arr,target,mid+1,r);
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        if(r==0)
            return false;
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            vector<int>arr=matrix[i];
            sort(arr.begin(),arr.end());
            if(bin_search(arr,target,0,c-1)){
                return true;
            }
        }
        return false;
    }
};