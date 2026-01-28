class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int mid = (i+j)/2;
        while(i<=j){
            cout<<i<<"+"<<j<<" "<<nums[mid]<<endl;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
            mid = (i+j)/2;
        }
        return -1;
    }
};