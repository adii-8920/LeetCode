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
  
  
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &index, int inorderStartIndex, int inorderEndIndex, int n){
        
        //base case
        if(index < 0 || inorderStartIndex > inorderEndIndex){
            return NULL;
        }
        
        int element= postorder[index--];
        TreeNode* root= new TreeNode(element);//Nayi node banadi
        int position= findPosition(inorder, element, n);//position nikaal li
        
        //recursive calls
        root->right= solve(inorder, postorder, index, position+1, inorderEndIndex, n);
        root->left= solve(inorder, postorder, index, inorderStartIndex, position-1, n);
        
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n= inorder.size();
        int postOrderIndex= n-1;
        TreeNode* ans= solve(inorder, postorder, postOrderIndex, 0, n-1, n);
        
        return ans;
    }
};