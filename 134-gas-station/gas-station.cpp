class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int n = g.size();
        int t = 0;
        int ts = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            t += g[i]-c[i];
            ts += g[i]-c[i];
            if(t<0){
                t=0;
                start = i+1;
            }
        }
        return ts<0? -1:start;
    }
};