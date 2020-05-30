class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<pair<int,double>> sq(points.size());
        for(int i=0;i<points.size();i++)
        {
            sq[i].first = i;
            sq[i].second = pow(points[i][0],2) + pow(points[i][1],2);
        }
        sort(sq.begin(),sq.end(), [](pair<int,double> a, pair<int,double> b){
            return a.second<b.second;
        });
        
        vector<vector<int>> ret;
        vector<int> temp;
        
        for(int i=0;i<K;i++)
        {
         
            ret.push_back({points[sq[i].first][0],points[sq[i].first][1]});

        }
        return ret;
    }
};
