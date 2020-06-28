class Solution {
public:

map<string, multiset<string>> targets;
    //multiset ensures appropriate lexical order
    //Similar to a set that can take multiple copies of one value

vector<string> route;

void visit(string airport) 
{
    while (targets[airport].size()) 
    {
        string next_destination = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        visit(next_destination);
    }
    
    route.push_back(airport);
}

    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        
       for (int i=0; i<tickets.size() ; i++)
        targets[tickets[i][0]].insert(tickets[i][1]);
        
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};
