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
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
    vector<int> temp;
    while(head!=NULL){
            temp.push_back(head->val);
            head = head->next;
    }
    sort(temp.begin(),temp.end());
    ListNode* ans = new ListNode(temp[0],NULL);
    ListNode* tm = ans;
    int n = temp.size();
    cout<<n;
    for(int i = 1; i<n; i++){
        ListNode* val = new ListNode(temp[i]);
        ans->next = val;
        ans = ans->next;
    }
    return tm;
    }
};