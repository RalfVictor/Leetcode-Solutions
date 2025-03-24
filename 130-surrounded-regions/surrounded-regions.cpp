class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> vis(n,vector<char>(m,'X'));
        queue<pair<int,int>> q;
        int row[] = {0,-1,0,1};
        int col[] = {-1,0,1,0};
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' ){
                vis[i][0]='O';
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                vis[i][m-1]='O';
                q.push({i,m-1});
            }
        }
            for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                vis[0][i]='O';
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                vis[n-1][i]='O';
                q.push({n-1,i});
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i]; 
                if(nr<n && nc<m && nr>=0 && nc>=0 && board[nr][nc]=='O' && vis[nr][nc]=='X'){
                    vis[nr][nc] = 'O';
                    q.push({nr,nc});
                }
            }
        }
        board = vis;
    }
};