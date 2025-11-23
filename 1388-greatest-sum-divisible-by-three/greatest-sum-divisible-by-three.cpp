class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0,-1,-1};
        for(int num:nums){
            vector<int> ndp = dp;
            for(int i=0;i<3;i++){
                if(dp[i]==-1) continue;
                int sum = dp[i]+num;
                int rem = sum%3;
                ndp[rem] = max(ndp[rem],sum);
            }
            dp = ndp;
        }
        return dp[0];
    }
};