class Solution {
public:
    int f(vector<int>& prices,int i,int buy,int cap,vector<vector<vector<int>>>& dp,int n){
        if(cap==0){
            return 0;
        }
        if(i==n) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap] = max(-prices[i]+f(prices,i+1,0,cap,dp,n),f(prices,i+1,1,cap,dp,n));
        }
        return dp[i][buy][cap] = max(prices[i]+f(prices,i+1,1,cap-1,dp,n),f(prices,i+1,0,cap,dp,n));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,0,1,2,dp,n);
    }
};