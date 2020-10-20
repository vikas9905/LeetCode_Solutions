//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    
    bool find(TreeNode *root,int k,map<int,int>&mp){
        if(root==NULL)
            return false;
        if(mp[k-root->val]!=0)
            return true;
        mp[root->val]=1;
        return find(root->left,k,mp) || find(root->right,k,mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
       map<int,int>mp;
       return find(root,k,mp);
    }
};