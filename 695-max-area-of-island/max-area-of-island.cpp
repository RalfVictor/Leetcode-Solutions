class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,int r, int c,int& temp,int n,int m){
        vis[r][c] = 0;
        temp++;
        int col[] = {0,1,0,-1};
        int row[] = {1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr = r+row[i];
            int nc = c+col[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==-1){
                bfs(grid,vis,nr,nc,temp,n,m);
            }
        }
        return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int temp = 0;
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                    bfs(grid,vis,i,j,temp,n,m);
                    ans = max(ans,temp);
                    temp = 0;
                }
            }
        }
        return ans;
    }
};