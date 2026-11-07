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
    TreeNode* inorderToBST(int s, int e, vector<int> &inorderVal){

    //base case
    if(s>e){
        return NULL;
    }

    int mid= (s+e)/2;
    TreeNode* root= new TreeNode(inorderVal[mid]);

    root->left= inorderToBST(s, mid-1, inorderVal);
    root->right= inorderToBST(mid+1, e, inorderVal);

    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return inorderToBST(0, nums.size()-1, nums);
    }
};