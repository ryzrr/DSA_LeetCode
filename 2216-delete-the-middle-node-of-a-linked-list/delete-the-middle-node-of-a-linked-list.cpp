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
    ListNode* deleteMiddle(ListNode* head) {
         
        ListNode* fast =head;
        int size=0;
        if(head->next==NULL) return NULL;
        while(fast!=NULL){
            size++;
            fast=fast->next;
        }
        fast=head;
        int n= size/2;
       for(int i=0;i<n-1;i++) fast=fast->next;

       if(fast->next==NULL) return  head->next;
       
       ListNode* delNode=fast->next;
       fast->next=fast->next->next;
    
       delete delNode;
       return head;
    }
};
  