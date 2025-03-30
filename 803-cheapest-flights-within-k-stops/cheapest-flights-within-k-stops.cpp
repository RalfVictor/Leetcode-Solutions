class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> pr(n,1e8);
        q.push({0,{src,0}});
        pr[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int s = q.front().second.first;
            int oprice = q.front().second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto it:adj[s]){
                int des = it.first;
                int nprice = it.second;
                if(nprice+oprice<pr[des]){
                    pr[des] = nprice+oprice;
                    q.push({stops+1,{des,nprice+oprice}});
                }
            }
        }
        if(pr[dst]==1e8){
            return -1;
        }
        return pr[dst];
    }
};