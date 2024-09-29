class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(count(temp.begin(),temp.end(),nums[i])<2){
                temp.push_back(nums[i]);
            }
        }nums=temp;
        return nums.size();
    }
};