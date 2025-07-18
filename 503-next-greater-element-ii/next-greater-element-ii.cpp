class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int flag = 0;
            for(int j=1;j<n;j++){
                if(nums[i]<nums[(j+i)%n]){
                    ans[i] = nums[(j+i)%n];
                    break;
                }
            }
        }
        return ans;
    }
};