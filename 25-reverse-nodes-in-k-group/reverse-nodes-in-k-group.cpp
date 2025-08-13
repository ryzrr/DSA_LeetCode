/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevGroup = &dummy, *curr = head, *nex = nullptr;

        
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        
        while (count >= k) {
            curr = prevGroup->next;
            nex = curr->next;

           
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = prevGroup->next;
                prevGroup->next = nex;
                nex = curr->next;
            }

            prevGroup = curr;
            count -= k;
        }
        return dummy.next; 
    }
};