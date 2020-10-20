//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    
    void level_order(TreeNode *root,vector<vector<int>>&ans){
        if(root==NULL)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*>tmp;
            vector<int>temp;
            while(!q.empty()){
            TreeNode* tp=q.front();
            q.pop();
            if(tp->left!=NULL)
                tmp.push(tp->left);
            if(tp->right!=NULL)
                tmp.push(tp->right);
              temp.push_back(tp->val);
            }
            ans.push_back(temp);
            q=tmp;
        }
        reverse(ans.begin(),ans.end());
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        level_order(root,ans);
        return ans;
    }
};