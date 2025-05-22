class Solution {
public:
    int f(vector<vector<int>>& tr,vector<vector<int>>& dp,int r,int c,int n){
        if(r==n-1) return tr[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int left = tr[r][c] + f(tr,dp,r+1,c,n);
        int right = tr[r][c] + f(tr,dp,r+1,c+1,n);
        return dp[r][c] = min(right,left);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(triangle,dp,0,0,n);
    }
};