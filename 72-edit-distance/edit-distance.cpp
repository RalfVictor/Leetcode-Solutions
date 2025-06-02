class Solution {
public:
    int f(int i,int j,string& text1,string& text2, vector<vector<int>>& dp){
        if(i==0){
            return j;
        }
        if(j==0){
            return i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i-1]==text2[j-1]){
            return  dp[i][j] = f(i-1,j-1,text1,text2,dp);
        }else{
            return dp[i][j] = 1+min(f(i,j-1,text1,text2,dp),min(f(i-1,j,text1,text2,dp),f(i-1,j-1,text1,text2,dp)));
        }
    }
    int minDistance(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,text1,text2,dp);
    }
};