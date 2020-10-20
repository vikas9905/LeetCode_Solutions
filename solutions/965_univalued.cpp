//https://leetcode.com/problems/univalued-binary-tree/

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
    bool ans=true;
    void find_ans(TreeNode* root,int data){
        if(root==NULL)
            return;
        if(root->val!=data){
            ans=false;
            return;
        }
        find_ans(root->left,data);
        find_ans(root->right,data);
    }
    bool isUnivalTree(TreeNode* root) {
        int data=root->val;
        find_ans(root,data);
        return ans;
    }
};