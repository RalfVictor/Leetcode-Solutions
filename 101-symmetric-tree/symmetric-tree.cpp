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
    void travel(TreeNode* p,TreeNode* q,bool &b){
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
        if(p->val!=q->val){
            b = false;
            return;
        }
        travel(p->left,q->right,b);
        travel(p->right,q->left,b);
    }

    bool isSymmetric(TreeNode* root) {
         bool b = true;
         if(!root){
            return b;
         }
        travel(root->left,root->right,b);
        return b;
    }
};