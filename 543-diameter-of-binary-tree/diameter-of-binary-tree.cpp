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
    int dfs(TreeNode* root,int& ans){
        if(!root){
            return 0;
        }
        int x = dfs(root->right,ans);
        int y = dfs(root->left,ans);
        ans = max(ans,x+y);
        return 1+max(x,y);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        int r = dfs(root,ans);
        return ans;
    }
};