class Solution {
public:
    int f(vector<int>& coins,int am,int ind,vector<vector<int>>& dp){
        if(ind==0){
            if(am%coins[ind]==0) return am/coins[ind];
            else return 1e9;
        }
        if(dp[ind][am]!=-1) return dp[ind][am];
        int nottake = 0+f(coins,am,ind-1,dp);
        int take = 1e9;
        if(am>=coins[ind]){
            take = 1+f(coins,am-coins[ind],ind,dp);
        }
        return dp[ind][am] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int x = f(coins,amount,n-1,dp);
        if(x==1e9) return -1;
        return x;
    }
};