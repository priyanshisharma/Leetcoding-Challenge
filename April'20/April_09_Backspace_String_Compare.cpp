class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='#')
            {
                if(i!=0)
                {
                    S.erase(i-1,2);
                    i-=2;
                } 
                else
                {   
                    S.erase(i,1);
                    i--;
                }
            }   
            
        }
        for(int i=0;i<T.size();i++)
        {
            if(T[i]=='#')
            {
                if(i!=0)
                {
                    T.erase(i-1,2);
                    i-=2;
                } 
                else
                {   
                    T.erase(i,1);
                    i--;
                }
            }
            
        }
       // cout<<S<<' '<<T;
        return (S==T);
        
    }
};
