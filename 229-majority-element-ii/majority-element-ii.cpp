class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        nums.clear();
        int val = n/3;
        for(auto i:mp){
            if(i.second>val){
                nums.push_back(i.first);
            }
        }
        return nums;
    }
};