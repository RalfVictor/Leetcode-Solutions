class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string ans = "";
        string v1 = strs[0];
        string v2 = strs[n-1];
        int m = min(v1.size(),v2.size());
        for(int i=0;i<m;i++){
            if(v1[i]!=v2[i]){
                return ans;
            }
            else{
                ans+=v1[i];
            }
        }
        return ans;
    }
};