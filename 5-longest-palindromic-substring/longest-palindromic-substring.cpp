class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int len = 0;
        int n = s.length();
        for(int i = 0 ;i<n;i++){
            int l = i;
            int r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>len){
                    len = r-l+1;
                    cout<<len<<endl;
                    ans = s.substr(l,len);
                }
            l--;
            r++;
            }
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>len){
                    len = r-l+1;
                    ans = s.substr(l,len);
                }
            l--;
            r++;
            }
        }
        return ans;
    }
};