class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        if(nums[0]==0) return false;
        int maxi = 0;
        for(int i=0;i<n-1;i++){
            if(i>maxi) return false;
            maxi = max(maxi,i+nums[i]);
            if(maxi>=n-1) return true;
        }
        return false;
    }
};