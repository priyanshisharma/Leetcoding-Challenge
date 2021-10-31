class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int t[text1.length()+1][text2.length()+1];
        for(int i=0; i<=text1.length();i++)
        {
            for(int j=0; j<=text2.length(); j++)
            {
                if(i==0||j==0)
                    t[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    t[i][j] = 1+t[i-1][j-1];
                else
                {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                } 
            }
        }
        return t[text1.length()][text2.length()];
    }
};
