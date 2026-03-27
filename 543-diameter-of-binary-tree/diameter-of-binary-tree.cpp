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
    int dfs(TreeNode* root,int& a){
        if(!root) return 0;
        int l = dfs(root->left,a);
        int r = dfs(root->right,a);
        a = max(a,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int ans = 0;
    int x = dfs(root,ans);
    return ans;
    }
};