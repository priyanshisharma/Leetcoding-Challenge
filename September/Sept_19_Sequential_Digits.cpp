class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        string digits="123456789";
        int len = digits.size();
        vector<int> ret;

        for(int i = 0; i < len; ++i) {
            for(int j = i; j < len; ++j) {
                string sub = digits.substr(i, j-i+1);
                int ans=stoi(sub);
                if(ans >= low && ans <= high) {
                    ret.push_back(ans);
                }
            }
        }

        sort(ret.begin(),ret.end());
        return ret;
    }
};
