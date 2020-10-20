//https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    
    long long find_decimal(vector<int> arr){
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=pow(2,i)*arr[i];
        }
        return ans;
    }
    
    vector<int> find_complement(long long n){
        vector<int>arr;
        if(n==0){
            arr.push_back(1);
            return arr;
        }
        while(n>=1){
            int rem=n%2;
            if(rem==0){
                arr.push_back(1);
            }
            else{
                arr.push_back(0);
            }
            n=n/2;
        }
        
        return arr;
    }
    
    int bitwiseComplement(int N) {
        vector<int> s=find_complement(N);
        long long ans=find_decimal(s);
        return ans;
    }
};