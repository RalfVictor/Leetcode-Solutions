class Solution {
public:
    int addDigits(int num) {
       int sum = 10;
        while(sum>9){
            sum = 0;
            while(num!=0){
                int x = num%10;
                sum+=x;
                num=num/10;
            }
            num=sum;
        }
        return sum;
    }
};