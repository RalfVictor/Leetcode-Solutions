class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int temp = 1;
        int ans = 1;
        int i = 1;
        while(i<n){
            if(nums[i]==nums[i-1]) {
                i++;
                continue;
            }
            if(nums[i]==nums[i-1]+1){
                temp++;
                i++;
            }
            else{
                ans = max(ans,temp);
                temp = 1;
                i++;
            }
        }
        ans = max(ans,temp);
        return ans;
    }
};