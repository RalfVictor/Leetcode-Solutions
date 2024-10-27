class Solution {
public:
    int binarysearch(vector<int>& arr, int s,int e, int key)
{
  int start = s;
  int end = e;
  int mid = start + (end - start) / 2;
  while (start <= end)
  {
    if (arr[mid] == key)
    {
      return mid;
    }
    if (arr[mid] < key)
    {
      start = mid + 1;
    }

    else
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return -1;
}

    int getPivot(vector<int>& nums, int n){
       int s=0,e=n-1;
  int mid = s+(e-s)/2;
  int ans;
  while(s<e){
    if(nums[mid]>=nums[0]){
      s = mid+1;
    }else{
      e=mid;
    }
    mid = s+(e-s)/2;
  }
  return s; 
    }

    int search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = getPivot(nums,n);
    if(target>=nums[pivot] && target <=nums[n-1]){
        return binarysearch(nums,pivot,n-1,target);
    }
    else{
        return binarysearch(nums,0,pivot-1,target);
    }
    }
};