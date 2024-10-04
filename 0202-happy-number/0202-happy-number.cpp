class Solution {
public:
    bool isHappy(int n) {
        int sum=0;
        vector<int> disp;
        int x=n;
        while(sum!=1){
            sum=0;
            while(x!=0){
                int y = x%10;
                sum+=(int)(pow(y,2));
                x/=10;
            }
            if(count(disp.begin(),disp.end(),sum)>0){
                return false;
            }
            disp.push_back(sum);
            x = sum;
        }
        return true;
    }
};