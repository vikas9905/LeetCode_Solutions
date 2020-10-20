//https://leetcode.com/problems/range-sum-of-bst/

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
    
    void sum_tree(TreeNode *root,int &sum,int l,int r){
        if(root==NULL)
            return;
        sum_tree(root->left,sum,l,r);
        if(root->val>=l && root->val<=r){
            sum+=root->val;
        }
        if(root->val>r)
            return;
        sum_tree(root->right,sum,l,r);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans=0;
        sum_tree(root,ans,L,R);
        return ans;
    }
};