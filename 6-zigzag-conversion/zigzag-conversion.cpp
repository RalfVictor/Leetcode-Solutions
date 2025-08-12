class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows<=1) return s;
        vector<string> x(n);
        int i = 0;
        int r = 0;
        while(i<n){
            while(i<n && r<numRows){
                x[r] = x[r]+s[i];
                i++;
                r++;
            }
            r = numRows-2;
            while(i<n && r>=0){
                x[r] = x[r]+s[i];
                i++;
                r--;
            }
            r = 1;
        }
        string ans = "";
        for(auto it:x){
            ans += it;
        }
        return ans;
    }
};