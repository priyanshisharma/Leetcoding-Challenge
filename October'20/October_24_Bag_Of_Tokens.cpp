class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        
        if(tokens.size() == 0)   // Base case
            return 0;
        
        sort(tokens.begin(),tokens.end());
        if(P < tokens[0])   // if P < minimum token value, we can't collect any points.
            return 0;
        int n = tokens.size();
        vector<int> prefix_sum(n,0);
        
        prefix_sum[0] = tokens[0];
        for(int i = 1;i<n;i++)
            prefix_sum[i] = prefix_sum[i-1] + tokens[i];
        
        int ans = lower_bound(prefix_sum.begin(),prefix_sum.end(),P) - prefix_sum.begin();   // Initialize answer with the value of points we can collect without playing any face down card.
        
        int power = P;
        for(int i = n-1 ; i >= n/2; i--){     // Running the loop till n/2 because face-up cards should be greater than face down to collexct points
             power += tokens[i];
          
            int points = lower_bound(prefix_sum.begin(),prefix_sum.end(),power) - prefix_sum.begin() - (n-i);    // Finding the number of points for a particular value of power.
            if(binary_search(prefix_sum.begin(),prefix_sum.end(),power)){
                points = points+1;    // Handling the case when Power of both the subsets are equal.
            }
           
            ans = max(ans,points);
        }
        return ans;
         
    }
};
