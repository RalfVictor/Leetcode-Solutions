class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    bool isValid(int r, int c, int n){
        if(r>=0 && r<n && c>=0 && c<n){
            return true;
        }
        return false;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 0) continue;
                int r[4] = {0,-1,0,1};
                int c[4] = {1,0,-1,0};
                for(int i=0;i<4;i++){
                    int nr = row+r[i];
                    int nc = col+c[i];
                    if(isValid(nr,nc,n) && grid[nr][nc]==1){
                        int node = row*n+col;
                        int adj = nr*n+nc;
                        ds.unionBySize(node,adj);
                    }
                }
            }
        }
        int mx = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 1) continue;
                int r[4] = {0,-1,0,1};
                int c[4] = {1,0,-1,0};
                set<int> st;
                for(int i=0;i<4;i++){
                    int nr = row+r[i];
                    int nc = col+c[i];
                    if(isValid(nr,nc,n)){
                        if(grid[nr][nc]==1 ){
                            st.insert(ds.findUPar(nr*n+nc));
                        }
                    }
                }
                int tot = 0;
                for(auto it:st){
                    tot+=ds.size[it];
                }
                mx = max(tot+1,mx);
            }
        }
        for(int i=0;i<n*n;i++){
            mx = max(mx,ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};