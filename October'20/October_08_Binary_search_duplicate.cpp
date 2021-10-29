
"https://leetcode.com/explore/featured/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3488/"


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0 ,r=nums.size();
        
        while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (nums[m] == target) 
            return m; 
  
        // If x greater, ignore left half 
        if (nums[m] < target) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    return -1; 
} 
  
};
