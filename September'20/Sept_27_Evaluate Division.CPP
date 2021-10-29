class Solution {
public:
    double bfs( unordered_map<string,unordered_map<string,double>> m, string src, string d){
          if(m.find(src) == m.end() || m.find(d) == m.end())
            return -1.0;
        queue<pair<string,double>> q;
        q.push({src,1});
        double fans=-1;
        set<string> visit;
    visit.insert(src);
        while(!q.empty()){
            pair<string,double> x= q.front();
            q.pop();
            string a=x.first;
            double f=x.second;
            if(a==d){
                fans=f;
                break;
            }
            for(auto i= m[a].begin();i!=m[a].end();i++){
           
           
                    if(visit.find(i->first)==visit.end()){
                        double l= i->second;
                        q.push({i->first,f*l});
                        visit.insert(i->first);
                    }
            }
        }
        return fans;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
         vector<double> ans;
        unordered_map<string,unordered_map<string,double>> m;
        for(int i=0;i<e.size();i++){
            m[e[i][0]][e[i][1]]=v[i];
             m[e[i][1]][e[i][0]]=1/v[i];
        }
            for(int i=0;i<q.size();i++){
                if(m.find(q[i][0])!=m.end()&&m.find(q[i][1])!=m.end()){
                ans.push_back(bfs(m,q[i][0],q[i][1]));
                }
                else{
                    ans.push_back(-1.0);
                }
            }
        return ans;
    }
};
