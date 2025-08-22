class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int n = s.size();
        int l = 0;
        int r = 0;
        int x = 0;
        int ans = 0;
        while(r<n){
            mp[s[r]]++;
            x = max(x,mp[s[r]]);
            if(r-l+1-x>k){
                mp[s[l]]--;
                l++;
            }
            if(r-l+1-x<=k){
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};