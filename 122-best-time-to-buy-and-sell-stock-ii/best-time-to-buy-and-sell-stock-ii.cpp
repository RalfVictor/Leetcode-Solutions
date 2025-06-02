class Solution {
public:
    int f(vector<int>& prices,int ind,int buy,vector<vector<int>>& dp,int n){
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy] = max(-prices[ind]+f(prices,ind+1,0,dp,n),f(prices,ind+1,1,dp,n));
        }
        return dp[ind][buy] = max(prices[ind]+f(prices,ind+1,1,dp,n),f(prices,ind+1,0,dp,n));
    }
    
    int maxProfit(vector<int>& Arr) {
    int n = Arr.size();
    vector<int> ahead(2, 0);
    vector<int> cur(2, 0);
    ahead[0] = ahead[1] = 0;
    int profit;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) {
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            }
            if (buy == 1) { 
                profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return cur[0];
    }
};