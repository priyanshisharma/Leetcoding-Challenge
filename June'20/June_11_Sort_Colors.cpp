class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int beg=0;
        int end=nums.size()-1;

        for(int i=0; i<=end; i++) 
        {

            if(nums[i]==0) 
            {
                int temp = nums[i];
                nums[i] = nums[beg];
                nums[beg] = temp;
                beg++;
            }
            else if(nums[i]==2) 
            {
                int temp = nums[i];
                nums[i] = nums[end];
                nums[end] = temp;
                end--;
                i--;
            }
        }
    
    }
};
