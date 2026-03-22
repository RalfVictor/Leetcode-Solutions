class Solution {
public:
    int loop(vector<int>& coins, int am, vector<vector<int>>& dp,int i){
        if(i==0){
            if(am%coins[i]==0){
                return dp[i][am] = am/coins[i];
            }
            return dp[i][am] = 1e9;
        }
        if(dp[i][am]!=-1) return dp[i][am];
        int notp = loop(coins,am,dp,i-1);
        int p = INT_MAX;
        if(am>=coins[i]){
            p = 1+loop(coins,am-coins[i],dp,i);
        }
        return dp[i][am] = min(notp,p);
    }
    int coinChange(vector<int>& coins, int am) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(am+1,-1));
        int ans = loop(coins,am,dp,n-1);
        if(ans==1e9) return -1;
        return ans;
    }
};