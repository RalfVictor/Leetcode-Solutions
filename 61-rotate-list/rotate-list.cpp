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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            len++;
        }        
        int rot = k%len;
        if(rot==0) return head;
        ListNode* newhead = head;
        for(int i=1;i<len-rot;i++){
            newhead = newhead->next;
        }
        tail->next = head;
        head = newhead->next;
        newhead->next = NULL;
        return head;
    }
};