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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* mid;
    TreeNode* last;
    void ino(TreeNode* root){
        if(!root) return;
        ino(root->left);
        if(prev!=NULL && (root->val < prev->val)){
            if(first==NULL){
                first = prev;
                mid = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        ino(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = mid = last = NULL;
        prev = new TreeNode(INT_MIN);
        ino(root);
        if(first && last) swap(first->val,last->val);
        else if(first && mid) swap(first->val,mid->val);
        return;
    }
};