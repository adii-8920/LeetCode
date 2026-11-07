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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight= true;
        
        while(!q.empty()){
            
            int size= q.size();//Loop ke andar aate hi hum check karte hain ki is level par kitne nodes hain aur unka count size mein lock kar dete hain.
            vector<int> ans(size);
            int index;
            
            //1 level processing
            //Normal Insert or Reverse Insert
            for(int i= 0; i< size; i++){//Ek Level Ki Processing (For Loop)
                
                TreeNode* frontNode= q.front();
                q.pop();
                
                if(leftToRight == true){
                    index= i;
                }
                if(leftToRight == false){
                    index= size-i-1;
                }
                
                //Index mil gaya h daalne ke liye
                ans[index]= frontNode->val;// data daal diya ya toh LtoR ya toh RtoL depending on index
                
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            
            //Direction Flip for next traverse
            leftToRight= !leftToRight;
            
            result.push_back(ans);
        }
    
        return result;
    }
};