/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
         node->val = node->next->val;
        
        // Store the next node temporarily
        ListNode* temp = node->next;
        
        // Skip the next node
        node->next = node->next->next;
        
        // Delete the skipped node to free memory
        delete temp;  
    }
};