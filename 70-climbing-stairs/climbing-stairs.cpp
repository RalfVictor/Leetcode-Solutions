class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int next = 1;
        for(int i=2;i<=n;i++){
            prev = next+prev;
            swap(prev,next);
        }
        return next;
    }
};