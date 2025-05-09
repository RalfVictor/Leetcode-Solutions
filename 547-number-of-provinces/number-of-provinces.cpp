class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        if(vis[node]) return;
        vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 0) return 0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};