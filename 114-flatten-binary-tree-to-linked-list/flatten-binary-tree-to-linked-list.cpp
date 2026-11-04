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
    void preorder(TreeNode* root, vector<int> &preorderVal){
        //base case
        if(root == NULL){
            return;
        }

        preorderVal.push_back(root->val);//N
        preorder(root->left, preorderVal);//L
        preorder(root->right, preorderVal);//R  
    }

    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        vector<int> preorderVal;
        preorder(root, preorderVal);//Store preorder
        int n= preorderVal.size();

        TreeNode* curr= root;

        //Starting me curr->0 index pe hai and temp->1 index pe

        for(int i= 1; i< n; i++){
            curr->right= new TreeNode (preorderVal[i]);
            curr->left= NULL;
            
            curr= curr->right;
        }

        //3rd Step
        curr->left= NULL;
        curr->right= NULL;
    }
};