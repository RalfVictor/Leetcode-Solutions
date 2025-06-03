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
        vector<int> ahead(n+1,0),curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int len = ahead[prev+1];
                if(prev==-1 || nums[i]>nums[prev]){
                len = max(len,1+ahead[i+1]);  
                }
                curr[prev+1] = len;
                }
                ahead = curr;
            }
        return curr[0];
    }
};