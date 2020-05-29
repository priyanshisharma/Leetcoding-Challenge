class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     
        
        if(prerequisites.size()==0)
            return true;
        
        int degreq[numCourses];
        int ctr=0;
        
         for (int i=0;i<numCourses;i++)
        {
            degreq[i] = 0;
        }
        
        for(int i=0;i<prerequisites.size();i++)
        {
            degreq[prerequisites[i][0]]++;       
        }
       

        stack<int> topSort;
        
        for(int i=0;i<numCourses;i++)
        {

            if(degreq[i] == 0)
                    topSort.push(i);
        }
        
        while(!topSort.empty())
        {
            int curr = topSort.top();
            topSort.pop();
            ctr++;
            
            for(int i=0;i<prerequisites.size();i++)
            {
                if(prerequisites[i][1]==curr)
                {
                   degreq[prerequisites[i][0]]--; 
                    
                    if(degreq[prerequisites[i][0]] == 0)
                        topSort.push(prerequisites[i][0]);
                } 
                
                
            }
            
        }
        
        return (ctr==numCourses);
        
    }
};
