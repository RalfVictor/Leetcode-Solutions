class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c[] = {1,-1,0,0};
        int r[] = {0,0,1,-1};
        deque<pair<int,int>> dq;
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        dq.push_front({0,0});
        ans[0][0] = 0;
        while(!dq.empty()){
            auto [a,b] = dq.front();
            dq.pop_front();
            for(int i=0;i<4;i++){
                int nr = a+r[i];
                int nc = b+c[i];
                if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                int dist = ans[a][b] + (grid[a][b] != i+1);
                if(dist < ans[nr][nc]){
                    ans[nr][nc] = dist;
                    if(grid[a][b] == i+1)
                    dq.push_front({nr,nc});
                    else
                    dq.push_back({nr,nc});
                }
            }
        }
        return ans[n-1][m-1];
    }
};