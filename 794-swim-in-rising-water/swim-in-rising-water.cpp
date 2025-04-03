class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> vis(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = 1;
        int row[] = {0,-1,0,1};
        int col[] = {1,0,-1,0};
        while(!pq.empty()){
            int lev = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==n-1) return lev;
            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                    pq.push({max(lev,grid[nr][nc]),{nr,nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};