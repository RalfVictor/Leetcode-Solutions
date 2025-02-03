class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        string final ="";
        vector <char> valu;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end() && count(valu.begin(),valu.end(),t[i])==0){
               mp[s[i]] = t[i];
               valu.push_back(t[i]);
            }
        }
        map<char,char>::iterator iter;
        for(int i=0;i<s.length();i++){
            iter = mp.find(s[i]);
            final = iter->second+final;
        }
        reverse(final.begin(),final.end());
        cout<<final;
        if(final==t){
        return true;}
        return false;
    }
};