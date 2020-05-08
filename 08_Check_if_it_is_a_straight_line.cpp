class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
       
        int i;
        float m1,m2;
        for(i=0;i+2<coordinates.size();i++)
        {
            m1 = (float)(coordinates[i+1][1] - coordinates[i][1])/(float)(coordinates[i+1][0] - coordinates[i][0]);
            m2 = (float)(coordinates[i+2][1] - coordinates[i+1][1])/(float)(coordinates[i+2][0] - coordinates[i+1][0]);
       
            
            if(m1!=m2)
                return false;
            
        }
        return true;
        
    }
};
