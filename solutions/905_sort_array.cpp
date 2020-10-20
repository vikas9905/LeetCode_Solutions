//https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int start;
        vector<int>arr_o;
        vector<int>even;
        for(int i=0;i<A.size();i++){
            if(A[i]%2==0){
                even.push_back(A[i]);
            }
            else{
                arr_o.push_back(A[i]);
            }
        }
         vector<int>ans;
        for(int i=0;i<even.size();i++)
            ans.push_back(even[i]);
        for(int i=0;i<arr_o.size();i++)
            ans.push_back(arr_o[i]);
        return ans;
        
    }
};