class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<int> freq(N,0);
        vector<int> trusted(N,0);
        int max = 0, mperson;
        for(int i=0;i<trust.size();i++)
        {
            freq[trust[i][0]-1]=-1;
            if(freq[trust[i][1]-1]!=-1)
                freq[trust[i][1]-1]++;
        }
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]==N-1)
                return i+1;
                
        }
        return -1;
    }
};
