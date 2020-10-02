class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        vector<vector<string>> ans(m.size());
        int i = 0;
        for (auto& it : m) {
            vector<string> str = it.second;
            sort(str.begin(), str.end());
            ans[i++] = str;
        }
        return ans;
    }
};