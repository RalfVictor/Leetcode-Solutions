class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int ans = 1;
        sort(nums.begin(),nums.end());
        if(n==1) return 1;
        if(n==0) return 0; 
        int temp = nums[0];
        for(int i=1;i<n;i++){
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