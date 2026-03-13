class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 1;
        int ans = 1;
        sort(nums.begin(),nums.end());
        if(nums.size()<=1){
            return nums.size();
        }
        int temp = nums[0];
        for(int i=1;i<nums.size();i++){
            if(temp == nums[i]) continue;
            if(temp+1 == nums[i]){
                temp = nums[i];
                maxi++;
            }
            else{
                ans = max(maxi,ans);
                temp = nums[i];
                maxi = 1;
            }
        }
        ans = max(maxi,ans);
        return ans;
    }
};