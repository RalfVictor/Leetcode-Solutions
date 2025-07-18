class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> x;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int flag = 0;
            for(int j=1;j<n;j++){
                if(nums[i]<nums[(j+i)%n]){
                    x[i] = nums[(j+i)%n];
                    if(x[i]==0) flag = 1;
                    break;
                }
            }
            if(flag == 1) ans.push_back(x[i]);
            else if(x[i]==0) ans.push_back(-1);
            else ans.push_back(x[i]);
        }
        return ans;
    }
};