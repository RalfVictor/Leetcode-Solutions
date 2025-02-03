class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        stack <char> sta;
        string ans;
        for(int i=0 ;i <n; i++){
            if(sta.empty()){
                sta.push(s[i]);
            }
            else if(sta.size()==1 && s[i]==')'){
                sta.pop();
            }
            else{
                if(s[i]=='('){
                    sta.push(s[i]);
                    ans+=s[i];
                }
                else{
                    sta.pop();
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};