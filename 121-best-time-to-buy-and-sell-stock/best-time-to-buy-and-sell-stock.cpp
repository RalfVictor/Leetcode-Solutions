class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int minind = 0;
        int price = 0;
        for(int i=0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            price = max(price,prices[i]-mini);
            } return price;
        }
};