class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        if(S=="")
            return {};
        
        vector<int> res;
        
        vector<int> ctr(26,0);
        for(int i=0;i<S.size();i++)
        {
            ctr[S[i]-'a']=i;
        }
        int beg = 0,end=0;
        for(int i=0;i<S.size();i++)
        {
            end = max(end, ctr[S[i]-'a']);
            if(i==end)
            {
                res.push_back(end-beg+1);
                beg=end+1;
            }
        }
        
        return res;
    }
};
