class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ' && temp.empty()){
                continue;
            }
            else{
                if(s[i]==' '){
                    ans = ans+temp+' ';
                    temp = "";
                }
                else if(i==0){
                    ans = ans+s[i]+temp;
                }
                else{
                    temp = s[i]+temp;
                }
            }
        }
        n = ans.length();
        if (ans[n-1]==' '){
            ans.erase(ans.begin()+n-1);
            return ans;
        }
        return ans;
    }
};