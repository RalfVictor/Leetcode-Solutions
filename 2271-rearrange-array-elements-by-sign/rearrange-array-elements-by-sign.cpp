class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        int i = 0;
        int j = 0;
        int count = 0;
        while(count<nums.size()){
            if(count%2 == 0){
                ans.push_back(pos[i]);
            i++;
            }
            else{
                ans.push_back(neg[j]);
            j++;
            }
            count++;
        }
        return ans;
    }
};