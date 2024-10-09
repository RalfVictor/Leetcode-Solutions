class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1=nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int s1=0;
        int s2=0;
        while(s1<n1 && s2<n2){
            //cout<<s1<<" "<<s2<<endl;
            if(nums1[s1]==nums2[s2]){
                ans.push_back(nums1[s1]);
                s1++;
                s2++;
            }else if(nums1[s1]>nums2[s2]){
                s2++;
            }
            else{
                s1++;
            }
            
        }return ans;
    }
};