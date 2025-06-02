class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> curr(2,0);
        vector<int> ahead(2,0);
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
             curr[buy] = max(-prices[ind]+ahead[0],ahead[1]);
                    }
            else curr[buy] = max(prices[ind]+ahead[1]-fee,ahead[0]);
            }
            ahead = curr;
        }
        return curr[1];
    }
};