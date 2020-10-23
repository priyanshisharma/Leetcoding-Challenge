class Solution {
public:    
    int bin_to_int(vector<int> b)
    {
          int ans=0;
        vector<int> inp=b;
        for(int i=0;i<inp.size();i++)
        {
            ans=ans+pow(2,i)*inp.at(i);
        }
        return ans;
    }
    
    int bitwiseComplement(int N) {
        int n=N;
        vector<int> ans;
        if(n==0) return 1;
        while(n>0)
        {   
            ans.push_back(n%2);
            n=n/2;
        }
        
        for(int i=0;i<ans.size();i++)
        {
            
            if(ans.at(i)==0)
            {
                ans.at(i)=1;
            }
            else
            {
                ans.at(i)=0;
            }
            
        }
        
        return bin_to_int(ans);
    }
};
