class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int maxi = 0;
        int c = 0;
        int i=0,j=0;
        while(j<n){
                if(nums[j]==0) c++;
                if(c>k){
                    if(nums[i]==0) c--;
                    i++;
                }
                ans = max(ans,j-i+1);
                j++;
            }
        
        return ans;
    }
};