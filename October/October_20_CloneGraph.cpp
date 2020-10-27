/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    //store the nodes
    unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        return dfs(node);
    }
    //dfs
    Node* dfs(Node* node) {
        //if node is present in map
        if (map.find(node) != map.end()) return map[node];
        //crete a new node
        Node* clone = new Node(node->val);
        map[node] = clone; // map OLD node to NEW node!
        for (Node* nei : node->neighbors)
            clone->neighbors.push_back(dfs(nei));
        return clone;
    }
};
