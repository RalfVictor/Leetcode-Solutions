class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = n/2;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>x) return nums[i];
        }
        return -1;
    }
};