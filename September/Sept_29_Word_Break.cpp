class Solution {
public:
    bool comp(vector<string>& wordDict, string s){
        int n= wordDict.size();
        for(int i=0;i<n;i++){
            if(wordDict[i]==s){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= wordDict.size();
        int m=s.size();
        bool dp[m+1];
        memset(dp, false, sizeof(dp));
        dp[0]=true;
        for(int i=1;i<=m;i++){
            if(dp[i]==false&&comp(wordDict, s.substr(i-1,1))&&i==1)
            {
                dp[i]=true;
            }
            else{
                for(int j=i-1;j>=0;j--){
                    if(dp[j]==true&&comp(wordDict, s.substr(j,i-j)))
                    {
                        dp[i]=true;
                    }
                }
            }
            
        }
        return dp[m];
    }
};
