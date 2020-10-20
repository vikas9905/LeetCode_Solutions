//https://leetcode.com/problems/leaf-similar-trees/

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
    
    void find_leaf(TreeNode *root,vector<int>&arr){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            arr.push_back(root->val);
        find_leaf(root->left,arr);
        find_leaf(root->right,arr);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1;
        vector<int>leaf2;
        find_leaf(root1,leaf1);
        find_leaf(root2,leaf2);
        //sort(leaf1.begin(),leaf1.end());
        //sort(leaf2.begin(),leaf2.end());
        if(leaf1.size()!=leaf2.size())
            return false;
        for(int i=0;i<leaf1.size();i++){
            if(leaf1[i]!=leaf2[i])
                return false;
        }
        return true;
    }
};