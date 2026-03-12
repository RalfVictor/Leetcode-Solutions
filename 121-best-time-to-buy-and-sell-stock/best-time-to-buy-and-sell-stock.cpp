class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        int ans = 0;
        int j = 0;
        for(int i=1;i<n;i++){
            if(prices[i]<prices[j]){
                j = i;
            }
            ans = max(ans,prices[i]-prices[j]);
        }
        return ans;
    }
};