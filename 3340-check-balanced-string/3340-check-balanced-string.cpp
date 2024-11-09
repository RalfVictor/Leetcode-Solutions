class Solution {
public:
    bool isBalanced(string num) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<num.length();i=i+2){
            int x  = (int)num[i]-'0';
            sum1+=x;
        }
        for(int i=1;i<num.length();i=i+2){
            int x  = (int)num[i]-'0';
            sum2+=x;
        }
        if(sum1==sum2){
            return 1;
        }
        return 0;
    }
};