class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(count(nums2.begin(),nums2.end(),nums1[i])>0){
                if(count(ans.begin(),ans.end(),nums1[i])==0){
                    ans.push_back(nums1[i]);
                }
            }
        }return ans;
    }
};