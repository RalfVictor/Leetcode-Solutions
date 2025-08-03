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
    void ino(TreeNode* root,vector<int>& temp){
        if(!root) return;
        ino(root->right,temp);
        temp.push_back(root->val);
        ino(root->left,temp);
    }
    bool findTarget(TreeNode* root, int target) {
        vector<int> nums;
        ino(root,nums);
        unordered_map<int,int> v;
        int n = nums.size();
        for(int i = 0;i<=n-1; i++){
            int b = target-nums[i];
            if(v.contains(b)== true){
                return true;
            }
            v[nums[i]]=i;
        }
        return false;
    }
};