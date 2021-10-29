class Solution {
public:
    
    void dfs(vector<vector<int>> &graph,vector<vector<int>> &ans,vector<int> &v,int p){
        if(p==graph.size()-1){
            ans.push_back(v);
            return ;
        }
        for(int i=0;i<graph[p].size();i++){ 
            v.push_back(graph[p][i]);
            dfs(graph,ans,v,graph[p][i]);  
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(0);
        dfs(graph,ans,v,0);
        
        return ans;
        
    }
};