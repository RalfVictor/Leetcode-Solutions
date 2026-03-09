class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp,int n,int m){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};
        int x = 1;
        for(int in=0;in<4;in++){
            int nr = i+row[in];
            int nc = j+col[in];
            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[i][j]<mat[nr][nc]){
                x = max(x,1 + dfs(nr,nc,mat,dp,n,m));
            }
        }
        return dp[i][j] = x;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(i,j,matrix,dp,n,m));
            }
        }
        return ans;
    }
};