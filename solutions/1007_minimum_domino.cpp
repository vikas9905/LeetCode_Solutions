//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution {
public:
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int s=A.size();
        vector<int> cnt_A(7,0);
        vector<int>cnt_B(7,0);
        vector<int>common(7,0);
        int min_rot=INT_MAX;
        int min_ind=-1;
        for(int i=0;i<s;i++){
            cnt_A[A[i]]++;
            cnt_B[B[i]]++;
            if(A[i]==B[i])
                common[A[i]]++;
        }
        for(int i=1;i<=6;i++){
            if(cnt_A[i]+cnt_B[i]-common[i]==s){
                cout<<i<< " ";
                min_rot=min({cnt_A[i],cnt_B[i],min_rot})-common[i];
            }
        }
        if(min_rot==INT_MAX)
            return -1;
        return min_rot;
    }
};