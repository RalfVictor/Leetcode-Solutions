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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        int size = arr.size();
        int i = 0;
        int j = size-1;
        while(i<j){
            if(arr[i]!=arr[j]){
                return 0; 
            }
            i++;
            j--;
        }
        return 1;
    }
};