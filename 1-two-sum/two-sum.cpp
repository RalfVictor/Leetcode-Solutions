class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int it = nums[i];
            if(mp.find(target-it)==mp.end()){
                mp[it] = i;
            }
            else{
                ans.push_back(mp[target-it]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};