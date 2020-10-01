// Run time : 4ms, better than 83.43% of cpp submissions
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1,0);
        for(int i : nums)
            if(i > 0 and i <= n)
                v[i] = 1;
        int x;
        for(int i = 1; i <= n; i++){
            if(v[i] != 1){
                x = i;
                break;
            }
        }
        return x;
    }
};
