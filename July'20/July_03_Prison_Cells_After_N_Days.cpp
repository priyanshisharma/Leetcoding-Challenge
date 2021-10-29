class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        vector<int> newcells(cells.size(),0);
        unordered_map<int, vector<int>> lookup;
        int looking=0;
        

        newcells[0] = newcells[cells.size() - 1] = 0;
        
        while(N--)
        {
            for(int i=1; i<cells.size()-1;i++)
                newcells[i] = 1 - cells[i-1]^cells[i+1];
            
            
             if(lookup.size()>0&&(lookup[0] == newcells))
               return lookup[N % lookup.size()];

            lookup.insert({looking++,newcells});                  
            
            cells=newcells;
            
        }

        return newcells;
    }
};
