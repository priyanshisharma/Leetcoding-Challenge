class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; // use vector to simulate stack.
        for (int i : a) {
            while (!s.empty() && s.back() > 0 && s.back() < -i)
                //remove from back
                s.pop_back();
            if (s.empty() || i > 0 || s.back() < 0)
                //add to back
                s.push_back(i);
            else if (i < 0 && s.back() == -i)
                s.pop_back();
        }
        return s;
    }
};
