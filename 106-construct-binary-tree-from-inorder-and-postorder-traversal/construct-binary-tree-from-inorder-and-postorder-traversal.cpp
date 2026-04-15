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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start ,  int end , int &postInd){
          if(start>end) return NULL;
          TreeNode* root =  new TreeNode(postorder[postInd]);
          postInd -- ;
          int i ;
          for(i=start;i<=end;i++){
            if(inorder[i] ==  root->val) break ;
          }
          root->right = solve(inorder,postorder ,i+1,end , postInd);
          root->left =   solve(inorder,postorder ,start ,i-1 , postInd);
          return root ; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int start =0 ;
        int postInd =  n-1;
        int end =n-1;

        return solve(inorder,postorder ,0,end , postInd);

    }
};