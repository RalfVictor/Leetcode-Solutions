class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,int i,int j,int n,int m){
        vis[i][j] = 1;
        int c[] = {0,1,0,-1};
        int r[] = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int nr = i+r[k];
            int nc = j+c[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && vis[nr][nc]==0){
                dfs(grid,vis,nr,nc,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j] == '1'){
                    ans++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return ans;
    }
};