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
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[i][buy][cap] = max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                    else dp[i][buy][cap] = max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};