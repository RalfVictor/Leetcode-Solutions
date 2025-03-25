class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph, int vis[], int col){
        vis[node] = col;
        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(dfs(it,graph,vis,!col)==false){
                    return false;
                }
            }
            if(vis[it]==col){
                return false;
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(dfs(i,graph,vis,0)==false){
                    return false;
                }
            }
        }
        return true;
    }
};