class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int next = 1;
        for(int i=2;i<=n;i++){
            int t = next;
            prev = next+prev;
            next = prev;
            prev = t;
        }
        return next;
    }
};