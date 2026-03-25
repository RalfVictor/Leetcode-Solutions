class Solution {
public:
    int rec(string& t1,string& t2,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j] = 1+rec(t1,t2,i-1,j-1,dp);
        }
        return dp[i][j] = max(rec(t1,t2,i-1,j,dp),rec(t1,t2,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return rec(text1,text2,n-1,m-1,dp);
    }
};