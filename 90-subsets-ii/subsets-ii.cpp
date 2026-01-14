class Solution {
public:
void solve(int n,int i,vector<int>& temp,vector<int>& nums,set<vector<int>>& st){
        if(n==i){
            return;
        }
        temp.push_back(nums[i]);
        st.insert(temp);
        solve(n,i+1,temp,nums,st);
        temp.pop_back();
        solve(n,i+1,temp,nums,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> temp;
        ans.push_back(temp);
        solve(nums.size(),0,temp,nums,st);
        for(auto& it:st){
            ans.push_back(it);
        }
        return ans;
    }
};