class Solution {
public:
    int binary_search(vector<int>& nums, int l, int r, int target) {
    
  if (l>r) {
    return -1;
  }

  int mid = l +(r-l)/2;

  if (nums[mid] == target) {
    return mid;
  }

  if (nums[l] <= nums[mid] && target <= nums[mid] && target >=nums[l]) {
    return binary_search(nums,l, mid-1, target);
  }

  else if (nums[mid] <= nums[r] && target >= nums[mid] && target <= nums[r]) {
    return binary_search(nums, mid+1, r, target);
  }

  else if (nums[r] <= nums[mid]) {
    return binary_search(nums, mid+1,r, target);
  }

  else if (nums[l] >= nums[mid]) {
    return binary_search(nums,l, mid-1, target);
  }

  return -1;
}
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size()-1, target);
    }
};
