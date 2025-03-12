class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({sr,sc});
        int r[] = {-1,0,1,0};
        int c[] = {0,1,0,-1};
        if(image[sr][sc]==color) return image;
        q.push({sr,sc});
        int init = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            vis[row][col] = 1;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r[i]+row;
                int nc = c[i]+col;
                if(nr>=0 && nr<n && nc>=0 && nc<m && init==image[nr][nc] && vis[nr][nc]==0){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
    return image;
    }
};