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

    TreeNode* createParentMapping(TreeNode* root, int target, map<TreeNode*, TreeNode*> &nodeToParent){
        
        TreeNode* res= NULL;//Target Node
        
        queue<TreeNode*> q;//level order traversal karne ke liye queue
        q.push(root);
        nodeToParent[root]= NULL;
        
        while(!q.empty()){
            
            TreeNode* front= q.front();
            q.pop();
            
            if(front->val == target){
                res= front;
            }
            
            if(front->left){
                nodeToParent[front->left]= front;//front->left ka parent front hai
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right]= front;//front->right ka parent front hai
                q.push(front->right);
            }
        }
        
        return res;//Target Node
    }
    
    int burnTree(TreeNode* root, map<TreeNode*, TreeNode*> &nodeToParent){
        
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;//level order traversal karne ke liye queue
        
        q.push(root);
        visited[root]= true;
        
        int ans= 0;
        
        while(!q.empty()){
            
            bool flag= false;//addition hua ya nahi queue me check karne ke liye flag variable
            int size= q.size();
            
            for(int i= 0; i< size; i++){
                //process neighbouring nodes
                
                TreeNode* front= q.front();
                q.pop();
                
                //if any addition in queue->increment time/ans
                if(front->left && !visited[front->left]){
                    flag= true;
                    q.push(front->left);
                    visited[front->left]= true;
                }
                
                if(front->right && !visited[front->right]){
                    flag= true;
                    q.push(front->right);
                    visited[front->right]= true;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag= true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]= true;
                }
            }
            
            if(flag == true){
                ans++;//time badha diya
            }
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        //algo:
        // step 1: create nodeToParent mapping
        // step 2: find target node
        //step 3: burn the tree in min time
        
        int ans= 0;
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode= createParentMapping(root, start, nodeToParent);
        
        ans= burnTree(targetNode, nodeToParent);
        
        return ans;
    }
};