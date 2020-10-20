//https://leetcode.com/problems/increasing-order-search-tree/

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
    TreeNode *new_node(int val){
        TreeNode *tmp=new TreeNode(val);
        return tmp;
    }
    void Inorder(vector<int>&ans,TreeNode *root){
        if(root==NULL)
            return;
        Inorder(ans,root->left);
        ans.push_back(root->val);
        Inorder(ans,root->right);
    }
    TreeNode *BuildTree(vector<int>ans){
        TreeNode *start=new TreeNode(ans[0]);
        TreeNode *tmp=start;
        for(int i=1;i<ans.size();i++){
            tmp->right=new_node(ans[i]);
            tmp=tmp->right;
        }
        return start;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *start=NULL;
        vector<int>ans;
        Inorder(ans,root);
        start=BuildTree(ans);
        return start;
    }
};