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
    void update(TreeNode* root,int val){

        if(val > root->val && root->right == NULL){
            TreeNode* temp = new TreeNode(val);
            root->right = temp;
            return;
        }
        if(val < root->val && root->left == NULL){
            TreeNode* temp = new TreeNode(val);
            root->left = temp;
            return;
        }
        if(val > root->val && root->right){
            update(root->right,val);
        }
        else{
            update(root->left,val);
        }
        return ;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* x = new TreeNode(val);
            return x;
        }
        update(root,val);
        return root;
    }
};