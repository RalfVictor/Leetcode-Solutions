class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int diff = nums1.size()-m;
  if(diff!=0){
  for(int i=0;i<diff;i++){
  nums1.pop_back();
  }
}
  for (int i = 0; i < n; i++)
  {
    nums1.insert(nums1.begin() + m, nums2[i]);
    m++;
  }
  sort(nums1.begin(),nums1.end());
    }
};