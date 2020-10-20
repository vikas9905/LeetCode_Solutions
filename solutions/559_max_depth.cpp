//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int find_depth(Node *root){
        if(root==NULL)
            return 0;
        int l=0;
        for(int i=0;i<root->children.size();i++){
           int d=find_depth(root->children[i]);
            l=max(l,d);
            
        }
        return l+1;
    }
    
    int maxDepth(Node* root) {
        return find_depth(root);
        
    }
};