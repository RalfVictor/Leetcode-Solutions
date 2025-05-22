class Solution {
public:
    int countw(vector<vector<int>>& dp, vector<vector<int>> ob, int r,int c){
        if(r>=0 && c>=0 && ob[r][c]==1) return 0;
        if(r==0 && c==0 ){
            return 1;
        }
        if((r<0 || c<0)) return 0;
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int left = countw(dp,ob,r-1,c);
        int right = countw(dp,ob,r,c-1);
        return dp[r][c] = left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countw(dp,obstacleGrid,m-1,n-1);
    }
};