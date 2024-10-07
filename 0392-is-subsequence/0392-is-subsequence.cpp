class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<char> sub;
        vector<char> sen;
        int n = s.length();
        int m = t.length();
        if(m<n){
            return false;
        }
        for(int i=0;i<n;i++){
            sub.push_back(s[i]);
        }
        for(int i=0;i<m;i++){
            sen.push_back(t[i]);
        }
        auto it = sen.begin();
        for(int i=0;i<n;i++){
            auto x = find(sen.begin(),sen.end(),sub[i]);
            if(count(sen.begin(),sen.end(),sub[i])==0 || x<it){
                return false;
            }
            if(count(sen.begin(),sen.end(),sub[i])>0){
                sen.erase(sen.begin(),(x+1));
                it = sen.begin();
            }
        }return true;
    }
};