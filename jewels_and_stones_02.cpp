class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int ctr = 0;
        set<char> j;
        for(int i=0;i<J.length();i++)
            j.insert(J[i]);
        
        for(int i=0;i<S.length();i++)
        {
            if(j.find(S[i])!=j.end())
                ctr++;
        }
        return ctr;
    }
};
