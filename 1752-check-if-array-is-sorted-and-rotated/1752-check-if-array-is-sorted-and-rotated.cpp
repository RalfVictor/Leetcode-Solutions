class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        vector<int> temp(nums.size());
        for(int j=0;j<nums.size();j++){
        for(int i=0;i<nums.size();i++){
            temp[(i+j)%nums.size()] = nums[i];
        }
        if(temp==sorted){
            return true;
        }
        }
        return false;
    }
};