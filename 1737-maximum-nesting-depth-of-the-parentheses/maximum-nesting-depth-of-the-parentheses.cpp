class Solution {
public:
    int maxDepth(string s) {
        stack<char> sta;
        int count = 0;
        int maxi = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(sta.empty())
                count = 0;
                sta.push(s[i]);
                count++;
                maxi = max(count,maxi);
            }
            else if(s[i]==')'){
                sta.pop();
                count--;
            }
        }
        return maxi;
    }
};