class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> temp(n,0);
        vector<int> ans(m,0);
        temp[0] = arr[0];
        for(int i=1;i<n;i++){
            temp[i] = temp[i-1]^arr[i];
        }
        for(int i=0;i<m;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(x==0){
                ans[i] = temp[y];
            }
            else{
                ans[i] = temp[x-1] ^ temp[y];
            }
        }
        return ans;
    }
};