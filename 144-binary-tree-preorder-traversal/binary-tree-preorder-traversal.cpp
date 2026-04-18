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
        // vector<int> result;
        // solve(root, result);
        // return result;
        // if(root == NULL) return {};
        // vector<int>ans;
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     root =st.top();
        //     st.pop();
        //     ans.push_back(root->val);
        //     if(root->right!=NULL) {
        //         st.push(root->right);
        //         }
        //     if(root->left!=NULL) {
        //         st.push(root->left);
        //         }
        // }
        // return ans;
          vector<int> ans;
            TreeNode* curr  = root;
            while(curr!=NULL){
                if(curr->left == NULL){
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
                else{
                    TreeNode* pred =  curr->left;
                    while(pred->right && pred->right != curr){
                        pred = pred->right;                    
                    }
                    if(pred->right == NULL ){
                            pred->right = curr;
                            ans.push_back(curr->val);
                            curr = curr->left;
                    }
                    else{
                        pred->right = NULL ;
                        
                        curr = curr ->right;
                    }
                }
            }
            return ans ;
        
    }

// private:
//     void solve(TreeNode* node, vector<int>& result) {
//         if (node == nullptr) return; 
//         result.push_back(node->val);  
//         solve(node->left, result);    
//         solve(node->right, result);   
//     }
};