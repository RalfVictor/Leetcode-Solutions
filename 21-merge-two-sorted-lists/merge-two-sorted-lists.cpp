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
        ListNode* head = new ListNode(-1);
        ListNode* start = head;
        while(list1 != NULL && list2 != NULL){
            if(list1->val >= list2->val){
                ListNode* x = new ListNode(list2->val);
                head->next = x;
                head = head->next;
                list2 = list2->next;
            }
            else{
                ListNode* x = new ListNode(list1->val);
                head->next = x;
                head = head->next;
                list1 = list1->next;
            }
        }
        if(list2 == NULL){
            while(list1){
                ListNode* x = new ListNode(list1->val);
                head->next = x;
                head = head->next;
                list1 = list1->next;
            }
        }
        else{
            while(list2){
                ListNode* x = new ListNode(list2->val);
                head->next = x;
                head = head->next;
                list2 = list2->next;
             }
        }
        return start->next;
    }
};