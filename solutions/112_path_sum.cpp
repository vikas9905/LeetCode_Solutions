//https://leetcode.com/problems/path-sum/

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
    int haspathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 1;
        cout<<hasPathSum(root->left,sum)+1;
        cout<<"\n";
        cout<<hasPathSum(root->right,sum);
        return 1;
    }
     bool hasPathSum(TreeNode* root, int sum) {
         haspathSum(root,sum);
         return false;
    }
};