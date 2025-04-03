class Solution {
public:
    int timer = 1;
    void dfs(int node,int parent,vector<int> &tin,vector<int> &low, vector<vector<int>> &adj, vector<vector<int>> &ans,vector<int> &vis){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,tin,low,adj,ans,vis);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> ans;
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> vis(n,0);
        dfs(0,-1,tin,low,adj,ans,vis);
        return ans;
    }
};