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
            // Custom Comparator (Universal Play Button)
            struct compare {
                bool operator()(ListNode* a, ListNode* b) {
                    return a->val > b->val; // Min-Heap ke liye '>' sign
                }
            };

            ListNode* mergeKLists(vector<ListNode*>& lists) {
                // Priority Queue jo ListNode ke pointers ko store karegi
                priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

                // Step 1: Saari lists ke Head nodes ko heap mein daalo
                for (int i = 0; i < lists.size(); i++) {
                    if (lists[i] != nullptr) {
                        minHeap.push(lists[i]);
                    }
                }

                // Dummy node jo nayi sorted list ka head banne mein madad
                // karega
                ListNode* dummy = new ListNode(0);
                ListNode* tail = dummy;

                // Step 2: Sabse chota nikalte jao, aur uske aage wala node
                // daalte jao
                while (!minHeap.empty()) {
                    ListNode* tmp = minHeap.top();
                    minHeap.pop();

                    // Nayi list mein chote node ko jodo
                    tail->next = tmp;
                    tail = tail->next;

                    // Agar us node ke aage aur elements hain, toh use heap mein
                    // push karo
                    if (tmp->next != nullptr) {
                        minHeap.push(tmp->next);
                    }
                }

                return dummy->next;
            
        
    }
};