class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int k=i;k<=j;k++){
            int cost = (cuts[j+1]-cuts[i-1])+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int x = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>> dp(x+2,vector<int>(x+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=x;j++)
            {
                if(i>j) continue;
                int mini = 1e9;
                for(int k=i;k<=j;k++){
                    int cost = (cuts[j+1]-cuts[i-1])+dp[i][k-1]+dp[k+1][j];
                    mini = min(mini,cost);
                    }
                dp[i][j] = mini;
            }
        }
        return dp[1][x];
    }
};