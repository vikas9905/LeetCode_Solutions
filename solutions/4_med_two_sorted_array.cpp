//https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,k=0;
        float ans;
        vector<int>arr(nums1.size()+nums2.size(),0);
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                arr[k]=nums1[i];
                i+=1;
                k+=1;
            }
            else if(nums1[i]>nums2[j]){
                arr[k]=nums2[j];
                j+=1;
                k+=1;
            }
            else{
                arr[k]=nums1[i];
                arr[k+1]=nums2[j];
                k+=2;
                i++;
                j++;
            }
        }
        while (i<nums1.size()){
            arr[k]=nums1[i];
            i+=1;
            k+=1;
        }
        while(j<nums2.size()){
            arr[k]=nums2[j];
            j+=1;
            k+=1;
        }
        if(arr.size()%2==0){
            ans=(arr[arr.size()/2]+arr[arr.size()/2-1])/(float)2;
        }
        else{
            ans=arr[arr.size()/2];
        }
        return ans;
    }
};