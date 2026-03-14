class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int i = 0;
        vector<vector<string>> ans;
        for(auto it:strs){
            string x = it;
            sort(it.begin(),it.end());
            mp[it].push_back(x);
            i++;
        }
        for(auto& it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};