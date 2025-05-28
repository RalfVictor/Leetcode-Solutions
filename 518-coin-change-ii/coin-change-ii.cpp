class Solution {
public:
int f(vector<int>& coins,int am,int ind,vector<vector<int>>& dp){
         if(ind==0){
            return am%coins[ind]==0;
        }
        if(dp[ind][am]!=-1) return dp[ind][am];
        int nottake = 0+f(coins,am,ind-1,dp);
        int take = 0;
        if(am>=coins[ind]){
            take = f(coins,am-coins[ind],ind,dp);
        }
        return dp[ind][am] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int x = f(coins,amount,n-1,dp);
        if(x==1e9) return -1;
        return x;
    }
};