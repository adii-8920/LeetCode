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
    void inorder(TreeNode *root, vector<int> &in){

    //base case
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){

    int i= 0, j= 0;
    vector<int> ans;

    while(i< a.size() && j< b.size()){
        if(a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i< a.size()){
        ans.push_back(a[i]);
        i++;
    }
    while(j< b.size()){
       ans.push_back(b[j]);
        j++;
    }

    return ans;
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
         //Step:1 -> Store Inorder
        vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);

        //Step:2-> Merge 2 sorted arrays
        vector<int> mergeArray= mergeArrays(bst1, bst2);

        return mergeArray;
    }
};