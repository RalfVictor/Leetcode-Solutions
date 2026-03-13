class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        if(nums.size()==1) return;
        for(int i=1;i<nums.size();i++){
            if(nums[j]==0 && nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            if(nums[j]!=0){
                j++;
            }
        }
        return;
    }
};