class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int> mp;
        int i = 0;
        int start = -1;
        int len = INT_MAX;
        int count = 0;
        int j = 0;
        for(auto& c:t){
            mp[c]++;
        }
        while(j<n){
            if(mp[s[j]]>0){
                count++;
            }
            mp[s[j]]--;
            j++;
            if(count==m){
                while(count==m){
                    if(len>j-i){
                            len = j-i;
                            start = i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count--;
                    }
                    i++;
                }
            }

        }
        return (start==-1)? "": s.substr(start,len);
    }
};