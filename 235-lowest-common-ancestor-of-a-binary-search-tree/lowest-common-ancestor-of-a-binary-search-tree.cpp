/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    //base case
    if(root == NULL){
        return NULL;
    }
    
    if(root->val > p->val && root->val > q->val){
        // a and b lie in left part toh unka LCA left me milega
        return lowestCommonAncestor(root->left, p, q);
    }
    if(root->val < p->val && root->val < q->val){
        // a and b lie in right part toh unka LCA right me milega
        return lowestCommonAncestor(root->right, p, q);
    }
    else{
        return root;
    }
    }
};