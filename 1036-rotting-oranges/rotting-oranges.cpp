class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int nco = 0;
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j]==1){
                    nco++;
                    vis[i][j] = 0;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int co = 0;
        int nr[] = {-1,0,1,0};
        int nc[] = {0,-1,0,1};
        int t = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            t = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row = r+nr[i];
                int col = c+nc[i];
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && vis[row][col]==0){
                    vis[row][col] = 1;
                    q.push({{row,col},t+1});
                    co++;
                }
            }
        }
        if(nco!=co) return -1;
        return t;
    }
};