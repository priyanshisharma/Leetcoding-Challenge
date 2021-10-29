class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int matrix[word1.size()+1][word2.size()+1];
        
        for(int i=0;i<=word1.size();i++)
        {
            for(int j=0;j<=word2.size();j++)
            {
                if(i==0)
                {
                    matrix[i][j] = j;
                }
                else if(j==0)
                {
                    matrix[i][j] = i;
                }
                
                else if(word1[i-1]==word2[j-1])
                {
                    matrix[i][j] = matrix[i-1][j-1];
                }
                else
                {
                    matrix[i][j] = min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1])) + 1;
                }
                
            }
        }
        
        
        return matrix[word1.size()][word2.size()];
    }
};
