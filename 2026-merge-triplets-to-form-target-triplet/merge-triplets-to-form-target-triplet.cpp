class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0];
        int y = target[1];
        int z = target[2];
        bool a = false;
        bool b = false;
        bool c = false;
        for(auto & t:triplets){
            if(t[0]<=x && y>=t[1] && z>=t[2]){
            if(x==t[0]) a = true;
            if(y==t[1]) b = true;
            if(z==t[2]) c = true;
            }
        }
        return a && b && c;
    }
};