/* Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums.
If target exists, then return its index, otherwise return -1.*/

class Solution {
    public int search(int[] nums, int target) {
        int len = nums.length;
        int position = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == target){
                position = i;
                break;
            }else{
                position = -1;
            }
        }
        return position;
        
    }
}
