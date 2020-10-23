//https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(l==0 or r==0){
            return max(l,r)+1;
        }
        return min(l,r)+1;
    }
};