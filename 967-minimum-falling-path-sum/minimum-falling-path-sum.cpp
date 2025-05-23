class Solution {
public:
    int f(vector<vector<int>>& dp,vector<vector<int>>& m,int r,int c,int n){
        if (c < 0 || c >= n) return 1e9;
        if (r == n) return 0;
        if (dp[r][c] != -1000000) return dp[r][c];
        int left = f(dp, m, r + 1, c - 1, n);
        int down = f(dp, m, r + 1, c, n);
        int right = f(dp, m, r + 1, c + 1, n);
        return dp[r][c] = m[r][c] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1000000));
        int res = 1e9;
        for (int j = 0; j < n; j++) {
            res = min(res, f(dp, matrix, 0, j, n));
        }
        return res;
    }
};