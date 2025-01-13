class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1){
                max++;
            }
            else{
                max = 0;
            }
            if(max>ans){
                    ans = max;
                }
        }
        return ans;
    }
};