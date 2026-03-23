class Solution {
public:
    int loop(vector<int>& nums,vector<vector<int>>& dp,int i,int prev,int n){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int len = loop(nums,dp,i+1,prev,n);
        if(prev==-1 || nums[i]>nums[prev]){
            len = max(len,1+loop(nums,dp,i+1,i,n));
        }
    return dp[i][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return loop(nums,dp,0,-1,n);
    }
};