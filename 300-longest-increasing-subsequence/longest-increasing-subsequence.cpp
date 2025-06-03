class Solution {
public:
    int f(vector<int>& nums,int i,int prev,vector<vector<int>>& dp,int n){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int len = f(nums,i+1,prev,dp,n);
        if(prev==-1 || nums[i]>nums[prev]){
            len = max(len,1+f(nums,i+1,i,dp,n));
        }
        return dp[i][prev+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp,n);
    }
};