class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int area = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(matrix[i][0]=='1'){
            dp[i][0] = 1;
            area = 1;}
        }
        for(int i=1;i<m;i++){
            if(matrix[0][i]=='1'){
            dp[0][i] = 1;
            area = 1;}
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    area = max(area,dp[i][j]*dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return area;
    }
};