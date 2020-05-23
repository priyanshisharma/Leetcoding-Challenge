class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> ret;
        
        int i=0,j=0,beg,end;
        
        while(i<A.size()&&j<B.size())
        {
            beg = max(A[i][0],B[j][0]);
            end = min(A[i][1], B[j][1]);
            
            if(beg<=end)
                ret.push_back({beg,end});
            
            if(A[i][1]<B[j][1])
                i++;
            else
                j++;
        }
        
        return ret;
        
        
    }
};
