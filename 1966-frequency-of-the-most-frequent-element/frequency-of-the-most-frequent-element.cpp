class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long i = 0;
        long j  = 0;
        long res = 0;
        long tot = 0;
        long n = nums.size();
        while(j<n){
            tot += nums[j];
            while((nums[j]*(j-i+1))>(tot+k)){
                tot-=nums[i];
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};