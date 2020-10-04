class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
        {
            return 0;
        }
        int n=matrix[0].size();
        vector<int>dp1(n+1,0);
        vector<int>dp2(n+1,0);
        int ans=0;
        bool key=0;
        for(int j=1;j<=matrix.size();j++)
        {
           key=1-key;
               for(int i=1;i<=n;i++)
        {
            if(matrix[j-1][i-1]=='1')
            {
                if(key)
                {
                     dp1[i]=1+min(dp1[i-1],min(dp2[i],dp2[i-1]));
                 //   cout<<dp1[i]<<" ";
                ans=max(dp1[i],ans);
                   
                }
                else
                {
                     dp2[i]=1+min(dp2[i-1],min(dp1[i],dp1[i-1]));
                ans=max(dp2[i],ans);
                  //  cout<<dp2[i]<<" ";
                       
                }
               
            }
            else
            {
                if(key)
                {
                      dp1[i]=0;
                   // cout<<"0"<<" ";
                }
                else
                {
                    dp2[i]=0;
                  ///  cout<<"0"<<" ";
                }
              
            }
        }
           // cout<<endl;
        }
     ans*=ans;
        return ans;
    }
};