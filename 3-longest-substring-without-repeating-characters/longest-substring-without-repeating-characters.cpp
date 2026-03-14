class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int i = 0;
        int j = 0;
        int ans = 0;
        int maxi = 0;
        unordered_map<char,int> mp;
        while(j<n){    
            mp[s[j]]++;
            maxi++;
            if(mp[s[j]]>1){
                while(mp[s[j]]>1 && i<n){
                    mp[s[i]]--;
                    i++;
                    maxi--;
                }
                ans = max(maxi,ans);
            }
            ans = max(maxi,ans);
            j++;
        }
        return ans;
    }
};