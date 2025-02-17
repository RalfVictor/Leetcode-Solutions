class Solution {
public:
    int myAtoi(string s) {
        long ans  = 0;
        int i = 0;
        int sign = 1;
        int len = s.length();
        while(i<len && s[i]==' '){
            i++;
        }
        if(i==len){
            return 0;
        }
        if(s[i]=='-'){
            sign = 0;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        while(s[i]>='0' && s[i]<='9'){
            ans = ans*10;
            if(ans<=INT_MIN || ans>=INT_MAX){
                break;
            }
            ans=ans+(s[i]-'0');
            i++;
        }
        cout<<i;
        if(!sign){
            ans = -1*ans;
        }
        if(ans<=INT_MIN){
            return INT_MIN;
        }
        if(ans>=INT_MAX){
            return INT_MAX;
        }
        return ans;
    }
};