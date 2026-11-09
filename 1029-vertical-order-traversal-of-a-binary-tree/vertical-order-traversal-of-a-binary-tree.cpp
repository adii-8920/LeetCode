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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int> > > nodes;
        queue<pair<TreeNode*, pair<int,int> >   > q;// hd , lvl
        
        vector<vector<int>> ans;
        
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()){
            
            pair<TreeNode*, pair<int,int> > temp= q.front();
            q.pop();
            
            TreeNode* frontNode= temp.first;
            int hd= temp.second.first;
            int lvl= temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->val);//Entry create kar di hai node ki
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+ 1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+ 1)));
            }
        }
        
        //nodes(map) me daal diya hai-> ab vertical wale store karenge
        for(auto i: nodes){//hd,(lvl,nodes)
            vector<int> arr;
            for(auto j: i.second){//lvl,nodes
                sort(j.second.begin(), j.second.end()); 
                for(auto k: j.second){//nodes
                    arr.push_back(k);
                }
            }
            ans.push_back(arr);
        }
            
        return ans;
    }
};

/*
Bhai step by step:

Tumhara map kuch aisa hai:

nodes[hd][lvl] = vector<int>

Example:

nodes[0][2] = {5,4}

Matlab column = 0, level = 2 par do nodes hain: 5 aur 4.

LeetCode 987 bolta hai ki agar same column aur same row par multiple nodes hain, to chhoti value pehle aani chahiye:

{4,5}

isliye sort karna padta hai.

Sort wahi kyun lagaya?

Ye loop dekho:

for(auto j : i.second)

Yahan j.second exactly wahi vector hai jo kisi particular (hd,lvl) ke nodes store kar raha hai.

Example:

j.second = {5,4}

To usi vector ko sort kar diya:

sort(j.second.begin(), j.second.end());

Ab ban gaya:

{4,5}

Phir jab tum niche push karoge:

for(auto k : j.second)
    arr.push_back(k);

to 4 pehle aur 5 baad mein jayega.
*/