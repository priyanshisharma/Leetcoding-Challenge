class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        map<int,vector<int>>pcs;
        
        for(int i=0; i<pieces.size(); i++)
        {
            pcs[pieces[i][0]]=pieces[i];
        }
        
        int j=0;
        while(j<arr.size())
        {
            if(pcs.find(arr[j])==pcs.end())
                return false;
            
            vector<int> temp=pcs[arr[j]];
            for(int k=0; k<temp.size(); k++)
            {
                if(temp[k]!=arr[j])
                {
                    return false;
                }
                
                j++;
                
            }
        }
        
        return true;
    }
};
