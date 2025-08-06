class Solution {
public:
    void solve(vector<vector<int>>& ans,int n,int i,vector<int>& temp,vector<int>& nums){
        if(n==i){
            return;
        }
        temp.push_back(nums[i]);
        ans.push_back(temp);
        solve(ans,n,i+1,temp,nums);
        temp.pop_back();
        solve(ans,n,i+1,temp,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        solve(ans,nums.size(),0,temp,nums);
        return ans;
    }
};