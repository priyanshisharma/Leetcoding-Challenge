class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        bool ret = false;
        if (dislikes.size() == 0)   
            return true;
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < dislikes.size(); i++) 
        {
            mp[dislikes[i][0]].push_back(dislikes[i][1]);
            mp[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        unordered_map<int, int> visited;
        
        for (int i = 1; i <=N; i++) 
        {
            if (visited.find(i) == visited.end()) 
            {
                queue<pair<int, int>> ver;
                ver.push(make_pair(i, 1));
                
                while (!ver.empty()) 
                {
                    int u = ver.front().first;
                    int color = ver.front().second;
                    ver.pop();
                    if (visited.find(u) != visited.end()) 
                    {
                        if (visited[u] != color)    
                            return false;
                        
                        continue;
                    }
                    
                    visited[u] = color;
                    
                    for (int j = 0; j < mp[u].size(); j++) 
                    {
                        ver.push(make_pair(mp[u][j], -1*color));
                    }
                } 
            }   
        }
        
        return true;
   
    }
};
