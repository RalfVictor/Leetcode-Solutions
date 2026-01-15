class Solution {
public:
    void dfs(string s,int i,int& ans,int n){
        if(i==n) {
            ans++;
            return;
        }
        if(s[i]=='0') return;
        dfs(s,i+1,ans,n);
        if(i+1<n && s[i]=='1' || (s[i]=='2' && (s[i+1]>='0' && s[i+1]<='6'))){
            dfs(s,i+2,ans,n);
        }
        return ;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        if(s[0]!='0')  dp[1] = 1;
        for(int i=2;i<=n;i++){
            string s1 = s.substr(i-1,1);
            string s2 = s.substr(i-2,2);
            if(s1>="1") {
                cout<<s1<<" ";
                dp[i]+=dp[i-1];
            }
            if(s2>="10" && s2<="26"){
                cout<<s2<<" "<<endl;
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};