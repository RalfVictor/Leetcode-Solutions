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
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(list1!=NULL && list2!=NULL){
            int a = list1->val;
            int b = list2->val;
            if(a<b){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else if(a>b){
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
            else{
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
        }
        if(list1 == NULL){
            temp->next = list2;
        }
        else if(list2 == NULL){
            temp->next = list1;
        }
        return dummy->next;
    }
};