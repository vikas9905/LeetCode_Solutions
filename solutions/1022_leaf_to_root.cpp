//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int path[33];
    int sum=0;
    
    int binary(int c){
        int ans=0;
        int j=0;
        for(int i=c;i>=0;i--){
            //cout<<path[i];
            ans+=pow(2,j)*path[i];
            j+=1;
        }
        //cout<<"\n";
        return ans;
    }
    
    void traverse(TreeNode *root,int c=0){
        if(root==NULL)
            return;
        else if(root->left!=NULL || root->right!=NULL ){
            path[c++]=root->val;
        }
        else if(root->left==NULL && root->right==NULL){
            path[c]=root->val;
            sum+=binary(c);
        }
        traverse(root->left,c);
        traverse(root->right,c);
    }
    int sumRootToLeaf(TreeNode* root) {
        traverse(root);
        return sum;
    }
};