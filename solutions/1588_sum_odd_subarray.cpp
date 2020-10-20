//https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

class Solution {
public:
    
    int sub_sum(vector<int> &arr,int k){
        int n=arr.size();
        int sum=0;
        for (int i = 0; i <= n - k; i++) { 
        for (int j = i; j < k + i; j++) 
            sum += arr[j]; 
        }
        
        return sum;
    }
    
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        for(int i=1;i<=n;i+=2){
            ans+=sub_sum(arr,i);
        }
        return ans;
    }
};