class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(count(temp.begin(),temp.end(),nums[i])>0){
                continue;
            }temp.push_back(nums[i]);
        }nums=temp;
        return nums.size();
    }
};