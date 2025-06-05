class Solution {
public:
    int f(int i,int n,vector<int>& arr,int k,vector<int>& dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int l = 0;
        int maxi = -1e9;
        int cost = -1e9;
        for(int j=i;j<min(i+k,n);j++){
            l++;
            maxi = max(maxi,arr[j]);
            int co = (l*maxi)+f(j+1,n,arr,k,dp);
            cost = max(cost,co);
        }
        return dp[i]=cost;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n;i>=0;i--){
        int l = 0;
        int maxi = -1e9;
        int cost = -1e9;
        for(int j=i;j<min(i+k,n);j++){
            l++;
            maxi = max(maxi,arr[j]);
            int co = (l*maxi)+f(j+1,n,arr,k,dp);
            cost = max(cost,co);
        }
        dp[i] = cost;
        }
        return dp[0];
    }
};