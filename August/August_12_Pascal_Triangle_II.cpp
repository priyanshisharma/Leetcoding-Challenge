class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> v;
        vector<int> sub_v;
        for(int i=0;i<=rowIndex;i++)
        {
            sub_v.push_back(1);
            for(int j=1;j<=i-1;j++)
            {
                sub_v.push_back(v[j-1]+v[j]);
            }
            if(i>0)
                sub_v.push_back(1);
            
            v=sub_v;
            sub_v.clear();
        }
        return v;
    }
};
