class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, vector<int>> mp ;
        
        //Creating map for elements and their dependencies
        for(int i=0; i<prerequisites.size();i++)
        {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // Number of dependencies  of all courses by their indegree
        vector<int> inDegree(numCourses,0);
        for(map<int, vector<int>> :: iterator itr = mp.begin(); itr!=mp.end();itr++)
        {
            for(int i=0; i<itr->second.size(); i++)
            {
                inDegree[itr->second[i]]++;
            }
        }
        
        //Inserting elements with no dependencise to start with
        queue<int> q;
        for(int i=0 ; i<inDegree.size(); i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        
        vector<int>res;
        while(!q.empty())
        {
            //Inserting elements without uncovered dependency
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            
            //Checking all elements whose dependency has just been covered
            for(int i=0; i<mp[curr].size();i++)
            {
                inDegree[mp[curr][i]]--;
                
                // If all dependencies covered, insert element
                if(inDegree[mp[curr][i]]==0) 
                    q.push(mp[curr][i]);                   
            }
        }
        
        // If an element is missed, no correct answer
        if(res.size()!=numCourses)
            return {}; 
        
        return res; 
        
            
    }
};
