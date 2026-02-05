class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int len = 0;
        int maxi = 0;
        vector<int> ans;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]] = i;
        }
        int i = 0;
        while(i<n){
            maxi = max(maxi,mp[s[i]]);
            len++;
            if(i==maxi){
                ans.push_back(len);
                len = 0;
                maxi = 0;
            }
            i++;
        }
        return ans;
    }
};