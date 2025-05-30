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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* t = temp.first;
            int l = temp.second;
                mp[l] = t->val;
            if(t->left){
                q.push({t->left,l+1});
            }
            if(t->right){
                q.push({t->right,l+1});
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};