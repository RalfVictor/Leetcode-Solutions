class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[i][j] = 1;
                else{
                int up = 0; 
                int down = 0;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    down = dp[i][j-1];
                }
                dp[i][j] = up+down;
            }
            }
        }
        return dp[m - 1][n - 1];
    }
};