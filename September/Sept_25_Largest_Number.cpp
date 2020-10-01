class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrs;
        
        for(int num : nums) {
            numStrs.emplace_back(to_string(num));
        }
        
        sort(numStrs.begin(), numStrs.end(), [](string &a, string &b) -> bool {
            int alen = a.length(), blen = b.length();
            int len = alen + blen;
            
            for(int i = 0; i < len; ++i) {
                if(a[i % alen] == b[i % blen]) continue;
                return a[i % alen] > b[i % blen];
            }
            return false;
        });
        
        string ans = "";
        for(string &str: numStrs) {
            ans += str;
        }
        
        // Erasing zeros from beginning
        int index = 0;
        while(index < ans.length() and ans[index] == '0') {
            ++index;
        }
        ans = ans.substr(index);
        if(ans == "") ans = "0";
        
        return ans;
    }
};
