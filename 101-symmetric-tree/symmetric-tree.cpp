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
    bool isSymmetric(TreeNode* root) {
        // Agar tree khali hai toh symmetric hai
        if (!root) return true;
        
        // Root ke left aur right subtrees ko compare karna shuru karo
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* p, TreeNode* q) {
        // Case 1: Dono side khali hain
        if (!p && !q) return true;
        
        // Case 2: Ek side khali hai ya values match nahi kar rahi
        if (!p || !q || p->val != q->val) return false;

        // Case 3: Mirror comparison
        // p ka left vs q ka right AND p ka right vs q ka left
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
};