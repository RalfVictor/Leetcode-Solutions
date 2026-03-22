class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        int same = image[sr][sc];
        q.push({sr,sc});
        while(!q.empty()){
            auto t = q.front();
            int r = t.first;
            int c = t.second;
            q.pop();
            image[r][c] = color;
            vis[r][c] = 1;
            int row[] = {0,-1,0,1};
            int col[] = {1,0,-1,0};
            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==same && vis[nr][nc]==-1) q.push({nr,nc});
            }
        }
        return image;
    }
};