class Solution {
public:
    bool check(string s, int i,int count,int n,vector<vector<int>>& dp){
        if(count<0){
            return false;
        }
        if(i==n){
            return (count==0);
        }
        if(dp[i][count]!=-1) return dp[i][count];
        if(s[i]=='(') return dp[i][count] = check(s,i+1,count+1,n,dp);
        else if(s[i]==')')return dp[i][count] = check(s,i+1,count-1,n,dp);
        else{
            return dp[i][count] = check(s,i+1,count+1,n,dp) || check(s,i+1,count-1,n,dp) || check(s,i+1,count,n,dp);
        }
    }

    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(n==1) return s[0]=='*';
        return check(s,0,0,n,dp);
    }
};