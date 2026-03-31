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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }

private:
    void solve(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        result.push_back(node->val);  
        solve(node->left, result);    // Traverse left
        solve(node->right, result);   // Traverse right
    }
};