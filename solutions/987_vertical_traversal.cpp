//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
map<int,int>level;
    
    bool comp(int a,int b){
        if(level[a]!=level[b])
            return level[a]<level[b];
        else
          return a<b;
    }
class Solution {
public:
    
    
    void traverse(map<int,vector<int> > &mp,TreeNode *root,int ht,int l=0){
        if(root==NULL){
            return;
        }
        mp[ht].push_back(root->val);
        level[root->val]=l;
        traverse(mp,root->left,ht-1,l+1);
        traverse(mp,root->right,ht+1,l+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        level.clear();
      map<int,vector<int> >mp;
      traverse(mp,root,0);
        vector<vector<int> >arr;
        map<int,vector<int> >::iterator i;
        for(i=mp.begin();i!=mp.end();i++){
            sort(i->second.begin(),i->second.end(),comp);
            arr.push_back(i->second);
        }
        return arr;
    }
};