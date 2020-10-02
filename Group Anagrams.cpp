class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        vector<vector<string>> ans;
        if(strs.size()==0) return ans;
        unordered_map<string, vector<string>>mp;
        
        for(int i=0;i<strs.size();i++)
        {
            string x= strs[i];
                
             vector<int >freq(26,0);
            for(int j=0;j<x.size();j++){
                freq[x[j]-'a']++;
            }
            
            string temp="";
            for(int k=0;k<26;k++){
                temp+=to_string(freq[k])+'_';
            }
            mp[temp].push_back(x);
           
        }
        
        for(auto it= mp.begin(); it!=mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
