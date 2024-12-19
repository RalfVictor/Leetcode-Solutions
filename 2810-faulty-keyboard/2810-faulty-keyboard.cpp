class Solution {
public:
    string finalString(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='i'){
                reverse(s.begin()+count,s.end()-(n-i-1));
                count++;
                cout<<s<<endl;
            }
        }
        s.erase(s.begin(),s.end()-(n-count));
        return s;
    }
};