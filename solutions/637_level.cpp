//https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    void find_level_avg(TreeNode *root,vector<double>&ans){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long long int sum=0,c=0;
            queue<TreeNode*>tmp;
            while(!q.empty()){
                TreeNode *tp=q.front();
                q.pop();
                sum+=tp->val;
                c+=1;
                if(tp->left!=NULL)
                    tmp.push(tp->left);
                if(tp->right!=NULL)
                    tmp.push(tp->right);
            }
            double avg=(double)sum/c;
            ans.push_back(avg);
            q=tmp;
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        find_level_avg(root,ans);
        return ans;
    }
};