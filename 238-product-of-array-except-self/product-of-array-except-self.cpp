class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n,1);
        vector<int> l(n,1);
        for(int i=1 , j=n-2; i<n; i++,j--){
            l[i] = l[i-1]*nums[i-1];
            r[j] = r[j+1]*nums[j+1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = l[i]*r[i];
        }
        return ans;
    }
};