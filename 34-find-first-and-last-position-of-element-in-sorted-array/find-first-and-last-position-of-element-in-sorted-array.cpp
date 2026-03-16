class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int start = -1;
        int end = -1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(nums[m]==t){
                start = m;
                j = m-1;
            }
            else if(nums[m]>t)  j = m-1;
            else i = m+1;
        }
        i = 0;
        j = n-1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(nums[m]==t){
                end = m;
                i = m+1;
            }
            else if(nums[m]>t)  j = m-1;
            else i = m+1;
        }
        return {start,end};
    }
};