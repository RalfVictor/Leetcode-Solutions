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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = new ListNode(-1,head);
        ListNode* temp = prev;
        for(int i=0;i<n;i++){
            head = head->next;
        }
        while(head){
            temp = temp->next;
            head = head->next;
        }
        temp->next = temp->next->next;
        return prev->next;
    }
};