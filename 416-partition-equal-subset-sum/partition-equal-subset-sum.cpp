class Solution {
public:
    bool f(vector<int>& nums,int n,int k,vector<vector<int>>& dp){
        if(k==0) return true;
        if(n==0) return k == nums[0];
        if(dp[n][k]!=-1) return dp[n][k];
        bool nott = f(nums,n-1,k,dp);
        bool take = false;
        if(nums[n]<=k) take = f(nums,n-1,k-nums[n],dp);
        return dp[n][k] = take || nott;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2) return false;
        sum = sum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(nums,n-1,sum,dp);
    }
};