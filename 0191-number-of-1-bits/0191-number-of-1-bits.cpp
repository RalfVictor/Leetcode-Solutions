class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n!=0){
            int x = n&1;
            n=n>>1;
            if(x==1){
                count++;
            }
        }
        return count;
    }
};