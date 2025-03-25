class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ind(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;
    }
};