class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int val = n/3;
        for(auto i:mp){
            if(i.second>val){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};