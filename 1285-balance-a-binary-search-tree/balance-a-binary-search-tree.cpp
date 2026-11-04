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
 /*Bhai, ekdum short aur crisp makkhan logic samajh:

### Hum kar kya rahe hain basically?

Hum ek tede-mede (unbalanced) tree ko pehle ek **Sorted Array (saaf suthri line)** mein badal rahe hain, aur fir us line ke ekdum **bich wale element (mid)** ko pakad-pakad kar ek naya, ekdum barabar (balanced) tree khada kar rahe hain.

### Isi approach se kyun kiya? (The Big Reason)

1. **BST ki Property:** BST ka `Inorder` traversal hamesha **Sorted Order (chote se bada)** deta hai. Toh humne `inorderVal` vector mein sorted data nikaal liya.
2. **Min Height / Balance ka Formula:** Agar tumhare paas ek sorted array hai, aur tum hamesha **bich wale element (`mid`) ko Root** banao, toh aadhe elements left mein jayenge aur aadhe right mein. Isse tree left aur right dono taraf ek?? barabar phailega aur height sabse kam (`minimum`) aayegi.

### 3 Steps mein Code ka Khel:

* **Step 1 (`inorder`):** Pure tree ka sorted vector nikal liya.
* **Step 2 (`mid` selection):** `(s + e) / 2` karke har baar bich ka element uthaya aur use `new TreeNode` bana diya.
* **Step 3 (Recursion connection):** `mid` ke left waale part se left tree jodd diya (`root->left`), aur right waale part se right tree jodd diya (`root->right`).

Complexity ekdum mast $O(N)$ baithti hai. Clear hai bhai?
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
    TreeNode* inorderToBST(int s, int e, vector<int> &inorderVal){

        //base case
        if(s>e){
            return NULL;
        }

        int mid= (s+e)/2;
        TreeNode* root= new TreeNode (inorderVal[mid]);

        root->left= inorderToBST(s, mid-1, inorderVal);
        root->right= inorderToBST(mid+1, e, inorderVal);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVal;
        inorder(root, inorderVal);//Store inorder-> Sorted Values
        int n= inorderVal.size();

        return inorderToBST(0, n-1, inorderVal);
    }
};