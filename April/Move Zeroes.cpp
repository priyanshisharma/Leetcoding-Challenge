class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int count_zero = count(nums.begin(), nums.end(), 0);
        vector<int> v;
        cout << "[";
        for (auto& it : nums) {
            if (it != 0) {
                cout << it << ",";
                v.push_back(it);
            }
        }
        while (count_zero--) {
            if (count_zero == 0) {
                cout << 0;
                v.push_back(0);
            } else {
                cout << 0 << ",";
                v.push_back(0);
            }
        }
        nums = v;
        cout << "]";
    }
};