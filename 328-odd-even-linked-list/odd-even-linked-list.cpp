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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ans = new ListNode(1);
        ListNode* fin = ans;
        ListNode* st1 = head;
        int x = 0;
        while(st1!=NULL){
            if(x%2==0){
                ListNode* temp = new ListNode(st1->val);
                ans->next = temp;
                ans = ans->next;
            }
            x++;
            st1=st1->next;
        }
        st1 = head;
        x = 0;
        while(st1!=NULL){
            if(x%2==1){
                ListNode* temp = new ListNode(st1->val);
                ans->next = temp;
                ans = ans->next;
            }
            x++;
            st1=st1->next;
        }
        st1 = head;
        return fin->next;
    }
};