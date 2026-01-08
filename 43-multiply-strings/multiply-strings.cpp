class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n = num1.length();
        int m = num2.length();
        vector<int> temp(n+m+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int pro = (num1[i]-'0')*(num2[j]-'0');
                temp[i+j] += pro;
            }
        }
        reverse(temp.begin(),temp.end());
        for(int i=n+m; i>=1; i--){
            temp[i-1] += temp[i]/10;
            temp[i] %= 10;
        }
        int zero = 0;
        while(zero <= n+m && temp[zero]==0){
            zero++;
        }
        if(zero == n+m+1) return "0";

        string ans = "";
        for(int i=zero;i<=n+m;i++){
            ans += to_string(temp[i]);
        }
        return ans;
    }
};