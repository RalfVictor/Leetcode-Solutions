class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> ans;
  int n = nums.size();
  int s = 0, e = n - 1;
  int mid = s + (e - s) / 2;
  int start = -1;
  int end = -1;
  while (s <= e)
  {
    if (nums[mid] == target)
    {
      start = mid;
      e = mid - 1;
    }
    else if (nums[mid] > target)
    {
      e = mid - 1;
    }
    else if (nums[mid] < target)
    {
      s = mid + 1;
    }
    mid = s + (e - s) / 2;
  }
  s = 0, e = n - 1;
  mid = s + (e - s) / 2;
  while (s <= e)
  {
    if (nums[mid] == target)
    {
      end = mid;
      s = mid + 1;
    }
    else if (nums[mid] > target)
    {
      e = mid - 1;
    }
    else if (nums[mid] < target)
    {
      s = mid + 1;
    }
    mid = s + (e - s) / 2;
  }
  ans.push_back(start);
  ans.push_back(end);
  return ans;
    }
    
};