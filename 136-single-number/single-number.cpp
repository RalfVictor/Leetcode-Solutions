class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(count(nums.begin(),nums.end(),nums[i])!=2){
                return nums[i];
            }
        }
        return -1;
    }
};