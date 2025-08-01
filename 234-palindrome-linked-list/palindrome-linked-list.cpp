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
  ListNode* reverseList(ListNode* head) {
    ListNode* previous = nullptr;
    ListNode* curr = head;
     if(head==NULL) return NULL;
     while(curr!=NULL){
        ListNode*  next= curr->next;
        curr->next=previous;
        previous=curr;
        curr=next;

     }
     return previous;
    }

    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode* fast =head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
          ListNode*newHead=reverseList(slow->next);
           ListNode*first=head;
            ListNode*second=newHead;
            while(second!=NULL){
                if(first->val!=second->val){
                     return false;
                     }
               first=first->next;
            second=second->next;
            }
            return true;
        


    }
};