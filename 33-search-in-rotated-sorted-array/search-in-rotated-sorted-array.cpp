class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int m = s + (e-s)/2;
        while(s<e){
            m = s + (e-s)/2;
            if(nums[m]>=nums[0]) s = m+1;
            else e = m;
        }
        int p = s;
        if(target == nums[p]) return p;
        if(target>nums[p] && target <= nums[n-1]){
            s = p;
            e = n-1;
        }
        else{
            s = 0;
            e = p-1;
        }
        while(s<=e){
            m = s + (e-s)/2;
            if(target == nums[m]) return m;
            if(nums[m]<target) s = m+1;
            if(nums[m]>target) e = m-1;
        }
        return -1;
    }
};