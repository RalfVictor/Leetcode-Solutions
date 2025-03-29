class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        queue<pair<int,pair<int,int>>> q;
        int r[] = {0,1,0,-1,-1,-1,1,1};
        int c[] = {1,0,-1,0,-1,1,-1,1};
        if(grid[0][0]==1) return -1;
        q.push({0,{0,0}});
        dist[0][0] = 0;
        while(!q.empty()){
            int d = q.front().first;
            int col = q.front().second.second;
            int row = q.front().second.first;
            q.pop();
            if(row==n-1 && col==n-1) return d+1;
            for(int i=0;i<8;i++){
                int nr = row+r[i];
                int nc = col+c[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==1e8 && grid[nr][nc]==0){
                    q.push({d+1,{nr,nc}});
                    dist[nr][nc] = d+1;
                }
            }
        }
        return -1;
    }
};