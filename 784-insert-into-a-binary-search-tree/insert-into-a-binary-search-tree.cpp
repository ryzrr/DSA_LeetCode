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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base Case: Agar tree poori tarah khali hai
        if (root == NULL) {
            return new TreeNode(val);
        }
        
        TreeNode* curr = root;
        
        while (true) {
            // Case 1: Value choti hai, Left jana padega
            if (val < curr->val) {
                // Agar left mein jagah khali hai, toh naya node wahi laga do
                if (curr->left == NULL) {
                    curr->left = new TreeNode(val);
                    break; // Node lag gaya, loop se bahar aao
                } 
                // Agar khali nahi hai, toh left aage badh jao
                else {
                    curr = curr->left;
                }
            } 
            // Case 2: Value badi hai, Right jana padega
            else {
                // Agar right mein jagah khali hai, toh naya node wahi laga do
                if (curr->right == NULL) {
                    curr->right = new TreeNode(val);
                    break; // Node lag gaya, loop se bahar aao
                } 
                // Agar khali nahi hai, toh right aage badh jao
                else {
                    curr = curr->right;
                }
            }
        }
        
        // Tree ka head (root) wapas kar do
        return root;
    }
};