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

    void inorder(TreeNode* root, vector<int> &inorderVal){

    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left, inorderVal);//L
    inorderVal.push_back(root->val);//N
    inorder(root->right, inorderVal);//R
}

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        inorder(root, inorderVal);//Store inorder-> Sorted Values

        int n= inorderVal.size();

        //Use 2 Pointer Approach to check if pair exists
        int i= 0, j= n-1;
        while(i<j){
            int sum= inorderVal[i] + inorderVal[j];

            if(sum == k){
                return true;
            }

            else if(sum > k){
                j--;
            }
            else{
                i++;
            }
        }

        return false;
    }
};