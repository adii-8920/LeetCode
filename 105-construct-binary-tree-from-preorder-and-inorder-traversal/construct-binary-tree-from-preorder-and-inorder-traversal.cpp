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

    int findPosition(vector<int> &inorder, int element, int n){
        for(int i= 0; i< n; i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }
  
  
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderStartIndex, int inorderEndIndex, int n){
        
        //base case
        if(index >= n || inorderStartIndex > inorderEndIndex){
            return NULL;
        }
        
        int element= preorder[index++];
        TreeNode* root= new TreeNode(element);//Nayi node banadi
        int position= findPosition(inorder, element, n);//position nikaal li
        
        //recursive calls
        root->left= solve(inorder, preorder, index, inorderStartIndex, position-1, n);
        root->right= solve(inorder, preorder, index, position+1, inorderEndIndex, n);
        
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex= 0;
        int n= inorder.size();
        TreeNode* ans= solve(inorder, preorder, preOrderIndex, 0, n-1, n);
        
        return ans;
    }
};