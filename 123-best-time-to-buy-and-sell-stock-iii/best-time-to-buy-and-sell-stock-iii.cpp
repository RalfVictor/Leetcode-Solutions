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
        vector<vector<int>> ahead(2,vector<int>(2+1,0));
        vector<vector<int>> curr(2,vector<int>(2+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        curr[buy][cap] = max(-prices[i]+ahead[0][cap],ahead[1][cap]);
                    }
                    else curr[buy][cap] = max(prices[i]+ahead[1][cap-1],ahead[0][cap]);
                }
            }
            ahead = curr;
        }
        return curr[1][2];
    }
};