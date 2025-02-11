class Solution {
public:
    string largestOddNumber(string num) {
        if(num==""){
            return "";
        }
        int n = num.length();
        int x = -1;
        for(int i=n-1;i>=0;i--){
            int y = num[i]-'0';
            if(y%2==1){
                x = i;
                break;
            }
        }
        if(x==-1){
            return "";
        }
        num.erase(num.begin()+x+1,num.end());
        return num;
    }
};