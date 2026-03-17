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
    void bfs(TreeNode* root,int& maxi,int h){
        if(!root){
            maxi = max(maxi,h-1);
            return;
        }
        bfs(root->left,maxi,h+1);
        bfs(root->right,maxi,h+1);
        return;
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxi = 0;
        bfs(root,maxi,1);
        return maxi;
    }
};