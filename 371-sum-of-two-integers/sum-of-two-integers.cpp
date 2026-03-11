class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int temp = a ^ b;
            b = a & b;
            a = temp;
            b = b<<1;
        }
        return a;
    }
};