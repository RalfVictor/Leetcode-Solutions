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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1!=l2){
            l1 = l1!=nullptr?l1->next:headA;
            l2 = l2!=nullptr?l2->next:headB;
        }
        return l1;
    }
};