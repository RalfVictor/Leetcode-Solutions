class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x;
        for(int i=0;i<=n;i++){
            if(count(nums.begin(),nums.end(),i)==0){
                x = i;
                break;
            }
        }
        return x;
    }
};