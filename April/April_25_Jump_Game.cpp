/*
https://leetcode.com/problems/jump-game/
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int step=nums[0];
        for(int i=1;i<size;++i){
            step--;
            if(step<0)
               return false;
            if(nums[i]>step)
               step=nums[i];
        }
        return true;
    }
};
