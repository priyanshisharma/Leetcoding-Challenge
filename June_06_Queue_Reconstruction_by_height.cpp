class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2)
    {
        if(v1[0]>v2[0])
            return true;
        else if(v1[0]==v2[0] && v1[1]<v2[1]) 
            return true;
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        int n = people.size();        
        vector<vector<int>> res;        
        sort(people.begin(),people.end(), comp);        
        
        for(int i=0;i<n;i++)
            res.insert(res.begin() + people[i][1], people[i]);

        return res;
    }
};
