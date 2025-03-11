class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int count = 0;
        int ncount = 0;
        int time = 0;
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                   
                }
                else if(grid[i][j]==1){
                    vis[i][j]=0;
                    ncount++;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int r[] = {-1,0,1,0};
        int c[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();
            for(int i=0;i<4;i++){
                int nr = row+r[i];
                int nc = col+c[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=2;
                    count++;
                }
            }
        }
        cout<<count<<" "<<ncount;
        if(ncount!=count){
            return -1;
        }
        return time;
    }
};