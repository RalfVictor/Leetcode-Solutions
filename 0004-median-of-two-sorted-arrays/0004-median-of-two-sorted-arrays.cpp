class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
  nums1.insert(nums1.end(), nums2.begin(), nums2.end());
  sort(nums1.begin(), nums1.end());
  int mid = (n - 1) / 2;
  cout << mid << " " << n <<endl;
  if (n & 1 == 1)
  {
    return double(nums1[mid]);
  }
  else
  {
    return double((nums1[mid] + nums1[mid + 1]))/2;
  }
    }
};