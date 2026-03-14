class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int i = 0;
        vector<string> temp = strs;
        vector<vector<string>> ans;
        for(auto it:temp){
            sort(it.begin(),it.end());
            mp[it].push_back(strs[i]);
            for(auto i:mp[it]){
            }
            i++;
        }
        for(auto& it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};