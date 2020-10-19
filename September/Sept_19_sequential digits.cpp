class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string num = "123456789";    
        
        for(int i=0; i<num.size(); i++) {
            
            for(int j=i; j<num.size(); j++) {
                
                int n = stoi(num.substr(i, j-i+1));  //Conversion of string to integer
                
                if ((n >= low) && (n <= high))
                    ans.push_back(n);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
    