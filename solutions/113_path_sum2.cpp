//https://leetcode.com/problems/path-sum-ii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>fpath;
    void in_path(int path[],int s){
        vector<int>arr;
        for(int i=0;i<s;i++)
            arr.push_back(path[i]);
        fpath.push_back(arr);
    }
    void find_path(TreeNode *root,int sum,int path[],int sum2,int c=0){
        if(root==NULL)
            return;
        sum2+=root->val;
        path[c]=root->val;
        c+=1;
        if(root->left==NULL && root->right==NULL && sum2==sum){
            in_path(path,c);
        }
        find_path(root->left,sum,path,sum2,c);
        find_path(root->right,sum,path,sum2,c);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int path[10000];
        memset(path,0,sizeof(path));
        int s=0;
        find_path(root,sum,path,s);
        return fpath;
    }
};