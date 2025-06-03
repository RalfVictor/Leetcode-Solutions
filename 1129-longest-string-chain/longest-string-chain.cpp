class Solution {
public:
    bool compare(string& str1,string& str2){
        if(str1.length()!=str2.length()+1){
            return false;
        }
        int f = 0;
        int sec = 0;
        while(f<str1.size()){
            if(sec < str2.size() && str1[f] == str2[sec]){
                f++;
                sec++;
            }
            else{
                f++;
            }
        }
        if(str1.size()==f && str2.size()==sec) return true;
        return false;
    }
    static bool comp(string& str1,string& str2){
        return str1.length()<str2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};