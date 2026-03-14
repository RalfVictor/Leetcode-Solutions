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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* temp = new ListNode(-1);
        ListNode* start = temp;
        while(list1 && list2){
            while(list1 && list2 && list1->val<=list2->val ){
                ListNode* dum = new ListNode(list1->val);
                temp->next = dum;
                temp = temp->next;
                list1 = list1->next;
            }
            while(list2 && list1 && list2->val<=list1->val ){
                ListNode* dum = new ListNode(list2->val);
                temp->next = dum;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        while(list1){
            ListNode* dum = new ListNode(list1->val);
            temp->next = dum;
            temp = temp->next;
            list1 = list1->next;
        }
        while(list2){
            ListNode* dum = new ListNode(list2->val);
            temp->next = dum;
            temp = temp->next;
            list2 = list2->next;
        }
        return start->next;
    }
};