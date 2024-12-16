class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    for(int i=0;i<k;i++){
        int x = *min_element(nums.begin(),nums.end());
        auto pt = find(nums.begin(),nums.end(),x);
        x = x*multiplier;
        nums.erase(pt);
        nums.insert(pt,x);
    }
        return nums;
    }
};