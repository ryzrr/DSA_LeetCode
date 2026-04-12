/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Har node ka baap (parent) kaun hai, ye save karo
        unordered_map<TreeNode*, TreeNode*> parent_map;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if(curr->left) { parent_map[curr->left] = curr; q.push(curr->left); }
            if(curr->right) { parent_map[curr->right] = curr; q.push(curr->right); }
        }

        // Step 2: Target se k distance tak BFS chalao
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int distance = 0;

        while(!q.empty()) {
            if(distance == k) break; // K kadam poore ho gaye!
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front(); q.pop();

                // Niche Left jao
                if(curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                // Niche Right jao
                if(curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                // Upar Parent ke paas jao
                if(parent_map[curr] && !visited[parent_map[curr]]) {
                    visited[parent_map[curr]] = true;
                    q.push(parent_map[curr]);
                }
            }
            distance++;
        }

        // Queue mein jo bacha hai, wahi result hai
        vector<int> result;
        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};