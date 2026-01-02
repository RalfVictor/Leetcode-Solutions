class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int a = nums.size()/2;
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]==a) return it;
        }
        return ans;
    }
};