/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void check(TreeNode* p, TreeNode* q, bool &b){
        if(!p && !q){
            return ;
        }
        if(!p){
            b = false;
            return;
        }
        if(!q){
            b= false;
            return;
        }
        if(p->val!=q->val){
            b = false;
            return;
        }
        check(p->left,q->left,b);
        check(p->right,q->right,b);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool b = true;
        check(p,q,b);
        return b;
    }
};