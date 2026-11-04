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
    bool solve(TreeNode* root, long min, long max){

    //base case
    if(root == NULL){
        return true;
    }

    if(root->val > min && root->val < max){// Phli node check ki aage poora tree recursive calls se check hoga
        
        bool left= solve(root->left, min, root->val);

        bool right= solve(root->right, root->val, max);

        return left && right;
    }

    return false;
    }
    bool isValidBST(TreeNode* root) {
        bool ans= solve(root, LONG_MIN, LONG_MAX);
        return ans; 
    }
};