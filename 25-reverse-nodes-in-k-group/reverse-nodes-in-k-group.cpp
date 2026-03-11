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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* PrevN = dummy;
        
        while(1){
            ListNode* n = PrevN;
            int t = k;
            while(t>0 && n){
                n = n->next;
                t--;
            }
            if(!n) break;
            ListNode* NextN = n->next;
            ListNode* prev = n->next;
            ListNode* curr = PrevN->next;
            while(curr != NextN){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = PrevN->next;
            PrevN->next = n;
            PrevN = temp;
        }
        return dummy->next;
    }
};