class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int j = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[j]){
                j = i;
            }
            ans = max(ans,prices[i]-prices[j]);
        }
        return ans;
    }
};