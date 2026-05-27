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

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse; // true = peeche se aayega (j), false = aage se aayega (i)
    
    // Helper function
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            // Agar reverse hai, toh Right mein ghuso. Warna Left mein ghuso.
            if (reverse == true) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    // Agla number nikalo
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        
        // Agar temp nikal gaya, toh uske opposite side ko stack mein daalo
        if (reverse == true) {
            pushAll(temp->left);
        } else {
            pushAll(temp->right);
        }
        
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        
        // Do iterators banaye: Ek aage se (l), Ek peeche se (r)
        BSTIterator l(root, false); 
        BSTIterator r(root, true);  
        
        int i = l.next(); // Tree ka sabse chota number
        int j = r.next(); // Tree ka sabse bada number
        
        // Classic Two Pointers Logic!
        while (i < j) {
            if (i + j == k) {
                return true; // Sum mil gaya!
            } 
            else if (i + j < k) {
                i = l.next(); // Sum chota pad raha hai, 'i' ko aage badhao
            } 
            else {
                j = r.next(); // Sum bada ho gaya, 'j' ko chota karo
            }
        }
        
        return false; // Loop khatam, sum nahi mila
    }
};