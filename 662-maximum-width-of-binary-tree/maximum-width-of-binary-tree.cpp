/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
      if(!root)  return  0;
      long long ans =0;
      queue<pair<TreeNode*,long long>>q;
      q.push({root,0});
      while(!q.empty())  
        {
            long long s = q.size();
            long long mmin = q.front().second; 
            long long first ,last;
            for(long long i =0;i<s;i++){
                long long curID = q.front().second - mmin;
                TreeNode* node  =   q.front().first;
                q.pop();
                if(i==0) first =  curID;
                if(i == s-1) last = curID;
                if(node->left){
                    q.push({node->left ,curID*2+1});
                }
                if(node->right){
                    q.push({node->right ,curID*2+2});
                }
                
            }
               ans= max (ans, last-first+1); 
        }
        return (int)ans; 
    }
};