class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> count(n,0);
        int mod = (int)(1e9+7);
        dist[0] = 0;
        count[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjn = it.first;
                int wei = it.second;
                if(dis+wei<dist[adjn]){
                    dist[adjn] = dis+wei;
                    pq.push({dis+wei,adjn});
                    count[adjn] = count[node];
                }
                else if(dis+wei==dist[adjn]){
                    count[adjn] = (count[adjn]+count[node])%mod;
                }
            }
        }
        return count[n-1]%mod;
    }
};