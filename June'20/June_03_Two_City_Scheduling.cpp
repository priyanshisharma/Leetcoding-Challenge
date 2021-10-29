class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int res=0,ctr1=0,ctr2=0,n=costs.size();
        vector<int> one, two;
        
        for(int i=0;i<n;i++)
        {
            if(costs[i][0]<costs[i][1])
            {
                ctr1++;
                res += costs[i][0];
                one.push_back(costs[i][1]-costs[i][0]);
            }
            else
            {
                ctr2++;
                res += costs[i][1];
                two.push_back(costs[i][0]-costs[i][1]);
            }
            
        }
      
        if(ctr1>n/2)
        {
            
            sort(one.begin(),one.end());
            int diff = ctr1-n/2;
            int i=0;
            while(ctr1>n/2)
            {
                res += one[i];
                i++; 
                ctr1--;
                ctr2++;
            }
        }
        else if(ctr2>n/2)
        {
            sort(two.begin(),two.end());
            int diff = ctr2-n/2;
            int i=0;
            
            while(ctr2>n/2)
            {
               
                res += two[i];
                i++; 
                ctr2--;
                ctr1++;
            }
        }
        
        return res;
    }
};
